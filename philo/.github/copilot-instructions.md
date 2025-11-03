# Copilot Instructions: Philosophers (42 Project)

## Project Overview
This is a **dining philosophers simulation** solving concurrency problems using pthreads and mutexes. Arguments: `./philo <philo_nbr> <time_to_die> <time_to_eat> <time_to_sleep> [max_meals]`. Times are in milliseconds and internally converted to microseconds (`* 1000`).

## Critical Architecture

### Thread-Safe Data Access Pattern
**ALL** shared data access MUST use getter/setter wrappers with mutex protection:
- `get_bool()`, `set_bool()` for booleans
- `get_long()`, `set_long()` for longs  
- `increase_long()` for atomic increments
- Example: `get_long(&philo->data->data_mutex, &philo->data->start_simulation)`

**Never** access `data->end_simulation`, `philo->last_mealtime`, `philo->full`, etc. directly outside mutexes.

### Fork Assignment Anti-Deadlock Strategy
In `init.c:fork_assign()`, forks are assigned by **ID ordering** (lowest ID first), not position:
```c
if (philo->first_fork->fork_id > philo->second_fork->fork_id)
    swap(first_fork, second_fork);  // Always acquire lower ID first
```
This prevents circular wait conditions. Never change fork ordering logic.

### Philosopher Desynchronization
`desync_philos()` staggers thread starts to prevent lock-step behavior:
- **Even count**: Even-numbered philos sleep `MIN_TIME` (60μs) before starting
- **Odd count**: Odd-numbered philos call `thinking(philo, true)` to calculate stagger

### Monitor Thread Pattern
The monitor (`monitor.c`) runs independently:
1. Waits for all philos to reach `threads_running_nbr == philo_nbr`
2. Polls death condition every `sleep_time` (adaptively: `time_to_die/10`, clamped 100-1000μs)
3. Uses `simulation_done()` (safe) to check exit, **never** direct access
4. Death check reads `last_mealtime` under `philo_mutex` lock

### Timing Conventions
- **Constants in microseconds**: `MIN_TIME=60000`, `MONITOR_DELAY=1000`
- **Parser multiplies by 1000**: Input 200ms → stored as 200000μs
- **Display in milliseconds**: `gettime(MILLISECOND)` for output timestamps
- `precise_usleep()` uses busy-wait for sub-millisecond accuracy

## Key Patterns

### Single Philosopher Edge Case
Must be handled separately (in `create_philosopher_threads()`):
```c
if (data->philo_nbr == 1)
    thread_handler(..., single_philo, ...);  // Special routine, no eat() call
```

### Safe Function Wrappers
Use `s_malloc()`, `thread_handler()`, `mutex_handler()` instead of raw calls. They include error checking with `t_opcode` enums (`LOCK`, `UNLOCK`, `INIT`, `DESTROY`, `CREATE`, `JOIN`).

### Simulation Lifecycle
1. `input_parse()` → validates args, converts times
2. `init_data()` → allocates philos/forks, initializes mutexes
3. `start_simulation()` → creates threads, starts monitor, joins all
4. `cleaner()` → destroys mutexes, frees memory

## Testing & Debugging

### Test Script
`my_tester.py` runs stress tests with iterations:
```bash
./my_tester.py --iterations 10 --times-to-eat 10
```
Failed tests log to `fails/` with format: `<args>_<iteration>.log`

### Real-World Bug Examples from Test Failures

#### Bug Type 1: Last Meal Time Race Condition (4-410-200-200-10)
**Symptom**: Philosopher dies at 835ms when `time_to_die=410ms`
```
601    1 is sleeping    (last update)
835    1 died           (234ms elapsed - should be safe!)
```
**Root Cause**: `last_mealtime` not updated atomically when eating starts. Monitor reads stale value.
**Fix**: Always use `set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND))` at start of `eat()`, protected by mutex.

#### Bug Type 2: Thinking Time Miscalculation (5-610-200-200-10)
**Symptom**: Philosopher 4 dies at 2413ms in odd-count scenario
```
2209   4 is thinking
2413   4 died        (204ms in thinking - expected <610ms total)
```
**Root Cause**: `thinking()` formula for odd numbers: `t_think = t_eat * 2 - t_sleep`. When `t_eat=200` and `t_sleep=200`, this gives 200μs thinking time. Philos miss their turn and starve.
**Fix**: Verify formula handles edge cases where `t_eat * 2 ≤ t_sleep` (should return 0, not negative).

#### Bug Type 3: High-Load Starvation (199-610-200-200-10)
**Symptom**: Philosopher 86 dies at 3012ms with 199 philosophers
```
2820   many philos eating/sleeping
3012   86 died
```
**Root Cause**: Thread scheduling delays with high thread count. `MONITOR_STARTUP_DELAY` insufficient for 199 threads to reach steady state.
**Fix**: Monitor may need adaptive startup delay based on `philo_nbr`. Also check `desync_philos()` even-count logic with 199 philos.

### Common Race Condition Sources
- **Writing status after `end_simulation` set** - check in `write_status()` before every printf
- **Monitor checking death without locking** - always lock `philo_mutex` before reading `last_mealtime`
- **Accessing `threads_running_nbr` without `data_mutex`** - use `all_threads_running()` or manual lock
- **Fork timestamp drift** - `last_mealtime` must be set IMMEDIATELY when acquiring forks, not after

### Debugging Checklist
When tests fail:
1. **Check log timestamps**: Calculate actual elapsed time between last meal and death
2. **Verify mutex coverage**: grep for direct struct access (`philo->full` vs `get_bool()`)
3. **Test both even/odd counts**: Bug may only appear with specific parity
4. **Run with helgrind**: `valgrind --tool=helgrind ./philo <args>` to catch data races
5. **Increase iterations**: Race conditions may be intermittent (1 in 10 runs)

### Timing Issues
If tests fail with ~199+ philosophers:
- Check monitor startup delay (`MONITOR_STARTUP_DELAY` = 5000μs may be insufficient)
- Verify `precise_usleep()` isn't drifting on busy systems (busy-wait vs usleep)
- Confirm `desync_philos()` calculations for odd numbers (THINKING_PERCENTAGE=0.62)
- Monitor polling interval may need tuning (currently `time_to_die/10`, clamped 100-1000μs)

## Build System

### Makefile
- Links with `libraries/libft/libft.a` (custom C library)
- Always use `-pthread` flag
- `make re` for clean rebuild
- Progress bar shows compilation status

### 42 Norm Compliance
- Max 25 lines per function
- No for loops (use `while (++i < n)` pattern)
- No variable declarations mid-function
- Header template mandatory in all `.c` files

## Common Pitfalls
1. **Don't use `simulation_done_unsafe()`** except inside locked sections
2. **Don't printf outside `write_mutex`** - causes interleaved output  
3. **Don't change `THINKING_PERCENTAGE` (0.62)** without recalculating odd-philo logic
4. **Don't forget to check `philo->full`** before writing status (prevents dead philo spam)
5. **Monitor sleep must be dynamic** - fixed delays cause failures with varying `time_to_die`

## File Organization
- `include/philo.h` - All structs, enums, prototypes, ANSI color macros
- `src/simulation*.c` - Core philosopher routine (`dinner_sim()`, `eat()`)
- `src/sync_utils.c` - Thread synchronization primitives
- `src/getter_setter.c` - Thread-safe accessors
- `src/monitor.c` - Death detection loop
- `src/mutexes.c`, `src/threads.c` - Safe wrappers with error handling

## When Making Changes
1. Always test with both even/odd philosopher counts (edge case differences)
2. Run `./my_tester.py` before committing (at least 10 iterations)
3. Check `fails/` logs for patterns (timestamp drift, specific philo IDs, meal counts)
4. Verify no data races with `helgrind`: `valgrind --tool=helgrind ./philo <args>`

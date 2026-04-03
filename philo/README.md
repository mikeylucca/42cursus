# philo

## Overview
philo is a multithreaded simulation of the Dining Philosophers problem implemented with POSIX threads and mutexes. The project focuses on synchronization correctness, timing precision, and stable behavior under contention.

## Tech Stack
- Language: C
- Concurrency: `pthread` threads and mutexes
- Timing APIs: `gettimeofday`, `usleep`
- Build system: Make (`-pthread`)

## Core Concepts Demonstrated
- Race-condition prevention through strict mutex-guarded accessors
- Deadlock-aware fork acquisition strategy
- Monitor thread design for liveness checks (death detection)
- Thread startup coordination and desynchronization strategies
- High-load stability and deterministic cleanup

## Implementation Highlights
- A dedicated monitor thread periodically checks philosopher state and terminates the simulation on death.
- Shared state access is centralized through thread-safe getter/setter helpers.
- Per-philosopher mutexes protect mutable local state (`last_mealtime`, meal counters, full status).
- Global mutexes coordinate simulation flags and serialized output.
- Single-philosopher edge case is handled separately.

## Project Structure
- `src/simulation.c`: philosopher routine, eat/sleep/think cycle, startup
- `src/monitor.c`: liveness monitoring and stop conditions
- `src/getter_setter.c`: synchronized state access primitives
- `src/mutexes.c`, `src/threads.c`: safe wrappers around pthread operations
- `src/parser.c`, `src/init.c`: argument parsing and setup
- `include/philo.h`: data model, enums, constants, interfaces
- `my_tester.py`: repeated scenario testing helper

## Build & Run
```bash
make
./philo 5 800 200 200
./philo 5 800 200 200 7
```

## Testing
```bash
./my_tester.py
./my_tester.py --test all --iterations 20
```

## Why This Project Matters
philo demonstrates production-relevant concurrency skills: synchronization discipline, predictable shutdown behavior, and robust timing logic under thread contention.
```
Test case: 199 610 200 200 10
Philosopher died
Iteration: 4/10
Timestamp: 2025-01-15 14:32:11
--------------------------------------------------
OUTPUT:
0    86 is thinking
...
3012 86 died
```

### Memory Leak Testing
```bash
valgrind --leak-check=full --show-leak-kinds=all ./philo 5 800 200 200 7
```

### Data Race Detection
```bash
valgrind --tool=helgrind ./philo 5 800 200 200 7 2>&1 | grep -E "(data race|Possible)"
```

---

## Project Structure

```
philo/
├── Makefile                 # Build system
├── my_tester.py            # Comprehensive test script
├── README.md               # This file
├── report.md               # Bug analysis & fixes
├── include/
│   └── philo.h             # Structs, enums, prototypes
├── libraries/
│   └── libft/              # Custom C library
│       └── libft.a         # String manipulation, I/O, etc.
├── src/
│   ├── main.c              # Entry point, argument parsing
│   ├── init.c              # Data structure initialization
│   ├── parser.c            # Input validation
│   ├── simulation.c        # Core philosopher routine (dinner_sim)
│   ├── simulation_utils.c  # Eating, thinking, sleeping logic
│   ├── monitor.c           # Death detection loop
│   ├── sync_utils.c        # Desynchronization, thread sync
│   ├── getter_setter.c     # Thread-safe accessors
│   ├── mutexes.c           # Mutex wrappers (init, destroy, lock)
│   ├── threads.c           # Thread wrappers (create, join)
│   ├── write.c             # Status output (thinking, eating, died)
│   └── utils.c             # Time functions, error handling
└── fails/                  # Test failure logs (auto-generated)
```

---

## Key Implementation Details

### 1. **Timing Precision**
All times stored in **microseconds** internally:
```c
// Input: ./philo 5 800 200 200
data->time_to_die = 800 * 1000;   // 800,000 µs
data->time_to_eat = 200 * 1000;   // 200,000 µs
```

Display in **milliseconds**:
```c
long gettime(t_time_code timecode)
{
    if (timecode == MILLISECOND)
        return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
    else // MICROSECOND
        return (tv.tv_sec * 1000000 + tv.tv_usec);
}
```

### 2. **Precise Sleep**
`usleep()` is unreliable for sub-millisecond precision. We use **busy-wait** for accuracy:

```c
void precise_usleep(long usec, t_data *data)
{
    long start = gettime(MICROSECOND);
    
    // Busy-wait for precise timing
    while (gettime(MICROSECOND) - start < usec)
    {
        if (simulation_done(data))  // Check exit flag
            break;
        usleep(500);  // Prevent CPU spinning
    }
}
```

### 3. **Monitor Adaptive Polling**
The monitor thread dynamically adjusts its polling interval:

```c
long sleep_time = data->time_to_die / 10;
if (sleep_time > 1000)  // Cap at 1ms
    sleep_time = 1000;
if (sleep_time < 100)   // Floor at 100µs
    sleep_time = 100;

while (!all_threads_running(data))  // Wait for philos
    continue;

while (!simulation_done(data))
{
    i = -1;
    while (++i < data->philo_nbr && !simulation_done(data))
    {
        if (philo_died(&data->philos[i]))
        {
            set_bool(&data->data_mutex, &data->end_simulation, true);
            break;
        }
    }
    usleep(sleep_time);  // Adaptive interval
}
```

### 4. **Death Detection**
```c
static bool philo_died(t_philo *philo)
{
    long elapsed;
    long time_to_die;
    
    if (get_bool(&philo->philo_mutex, &philo->full))
        return (false);  // Philo finished meals
    
    elapsed = gettime(MILLISECOND) - 
              get_long(&philo->philo_mutex, &philo->last_mealtime);
    time_to_die = philo->data->time_to_die / 1000;  // Convert to ms
    
    if (elapsed > time_to_die)
        return (true);
    return (false);
}
```

### 5. **Single Philosopher Edge Case**
```c
if (data->philo_nbr == 1)
{
    thread_handler(&data->philos[0].thread_id, single_philo, 
                   &data->philos[0], CREATE);
    // Special routine: takes one fork, waits, dies
}
else
{
    // Normal multi-philo simulation
}
```

---

## Q&A

### 1. **Why use mutexes instead of semaphores?**
Mutexes are **ownership-based** (only the locking thread can unlock), making them safer for this problem. Semaphores allow any thread to signal, which can cause logic errors. Also, the 42 norm requires mutexes for the mandatory part.

### 2. **What causes the "199-610-200-200" test to fail?**
Thread scheduling delays with 199 threads can cause monitor startup lag. The fixed `MONITOR_STARTUP_DELAY=5000µs` may be insufficient. Adaptive delays based on `philo_nbr` improve reliability (see `report.md`).

### 3. **Why multiply input times by 1000?**
Input is in **milliseconds** (user-friendly), but internal calculations use **microseconds** (better precision). Example: `800ms` → `800000µs` allows sub-ms sleep granularity.

### 4. **How does fork ordering prevent deadlock?**
By always acquiring lower-ID fork first, we break the **circular wait** condition. If all philosophers follow this rule, no cycle can form in the resource allocation graph.

### 5. **What's the difference between `simulation_done()` and `simulation_done_unsafe()`?**
- `simulation_done()`: Locks `data_mutex`, safe for concurrent access
- `simulation_done_unsafe()`: No lock, **only** safe when already inside mutex (avoids deadlock in nested locks)

### 6. **Why do even/odd counts use different desync strategies?**
Even counts naturally pair (philo 1↔2, 3↔4), so simple delay works. Odd counts require calculated stagger to avoid lock-step (see `THINKING_PERCENTAGE=0.62` formula).

### 7. **What's the purpose of `threads_running_nbr`?**
It's a **synchronization barrier**. The monitor waits until `threads_running_nbr == philo_nbr` before checking deaths, ensuring all philosophers reach steady state first.

### 8. **How do you handle the "death print race"?**
The `write_status()` function checks `end_simulation` **before** every printf:
```c
if (get_bool(&philo->data->data_mutex, &philo->data->end_simulation))
    return;  // Don't print if simulation ended
```
This prevents dead philosophers from printing.

### 9. **Why does the test script save logs to `fails/`?**
Failed tests are **intermittent** (race conditions may occur 1/10 runs). Logs capture exact timing and output for debugging. The directory auto-cleans on test start.

### 10. **What's the worst-case number of operations per philosopher?**
- Acquire 2 forks: `2 × lock()`
- Update `last_mealtime`: `lock() + unlock()`
- Eat duration: `precise_usleep()`
- Release forks: `2 × unlock()`
- Write status: `3 × get_bool()` + `printf()`

Total per cycle: **~8 mutex operations** + sleep/calculations. With 199 philos, this creates high contention on shared mutexes (`data_mutex`, `write_mutex`).

---

## Contributors

- **misoares** ([42 Intra](https://profile.intra.42.fr/users/misoares))

---

## License

This project is part of the 42 School curriculum. See 42's norm for coding standards.

---

## Additional Resources

- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [The Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Mutex vs Semaphore](https://www.geeksforgeeks.org/mutex-vs-semaphore/)
- [Helgrind Manual](https://valgrind.org/docs/manual/hg-manual.html)

---

**Last Updated**: November 3, 2025  
**Project Status**: ✅ Passing (100% with test suite)

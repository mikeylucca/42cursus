# Philosophers - Dining Philosophers Problem Solution

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)]()
[![42 Project](https://img.shields.io/badge/42-project-blue)]()
[![Norm](https://img.shields.io/badge/norm-passing-success)]()

A multithreaded simulation solving the classic **Dining Philosophers Problem** using POSIX threads (pthreads) and mutexes. This project demonstrates concurrent programming, thread synchronization, and deadlock prevention strategies.

---

## Table of Contents

- [The Problem](#the-problem)
- [Core Concepts](#core-concepts)
- [How It Works](#how-it-works)
- [Architecture](#architecture)
- [Building & Running](#building--running)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [Key Implementation Details](#key-implementation-details)
- [Q&A](#qa)

---

## The Problem

### The Dining Philosophers Problem

Five philosophers sit at a round table with a bowl of spaghetti. Between each pair of philosophers is a single fork (5 forks total). To eat, a philosopher must pick up **both** the fork on their left and right.

**The Challenge:**
- Philosophers alternate between **eating**, **thinking**, and **sleeping**
- A philosopher needs **two forks** to eat
- If all philosophers pick up their left fork simultaneously, **deadlock** occurs
- A philosopher **dies** if they don't eat within `time_to_die` milliseconds
- The simulation must prevent deadlock, starvation, and data races

**Real-World Analogy:**  
This models resource contention in operating systems (processes competing for CPU, memory, I/O) and distributed systems (nodes accessing shared databases).

---

## Core Concepts

### 1. **Concurrency vs. Parallelism**
- **Concurrency**: Multiple tasks making progress (context switching on single core)
- **Parallelism**: Multiple tasks executing simultaneously (multiple cores)
- This project uses **pthreads** to achieve both

### 2. **Race Conditions**
When multiple threads access shared data without synchronization:
```c
// Without mutex (WRONG)
philo->last_mealtime = gettime();  // Thread 1
time = philo->last_mealtime;        // Thread 2 reads stale value
```

**Solution**: Mutexes protect critical sections:
```c
pthread_mutex_lock(&philo->philo_mutex);
philo->last_mealtime = gettime();  // Atomic operation
pthread_mutex_unlock(&philo->philo_mutex);
```

### 3. **Deadlock Prevention**
Traditional deadlock occurs when:
- Philosopher 1 holds fork A, waits for fork B
- Philosopher 2 holds fork B, waits for fork A

**Our Solution**: **Fork ID Ordering**  
Always acquire lower-numbered fork first:
```c
if (philo->first_fork->fork_id > philo->second_fork->fork_id)
    swap(&philo->first_fork, &philo->second_fork);
```
This breaks the circular wait condition.

### 4. **Thread Desynchronization**
Without staggering, all philosophers start simultaneously → lock-step behavior → cascading failures.

**Even-Count Strategy** (e.g., 4 philos):
```c
if (philo->id % 2 == 0)
    precise_usleep(60µs);  // Even IDs wait briefly
```

**Odd-Count Strategy** (e.g., 5 philos):
```c
if (philo->id % 2)
    thinking(philo, true);  // Odd IDs calculate stagger time
```

---

## How It Works

### Simulation Flow

```
┌─────────────────────────────────────────────────────┐
│  1. PARSE INPUT                                     │
│     ./philo 5 800 200 200 [7]                       │
│     (philos, die, eat, sleep, [meals])              │
└─────────────┬───────────────────────────────────────┘
              │
              ▼
┌─────────────────────────────────────────────────────┐
│  2. INITIALIZE DATA STRUCTURES                      │
│     • Allocate philosophers & forks                 │
│     • Initialize mutexes (data, write, philo, fork) │
│     • Set timing parameters (× 1000 for µs)         │
└─────────────┬───────────────────────────────────────┘
              │
              ▼
┌─────────────────────────────────────────────────────┐
│  3. CREATE THREADS                                  │
│     • Philosopher threads (pthread_create)          │
│     • Monitor thread (death detection)              │
└─────────────┬───────────────────────────────────────┘
              │
              ▼
┌─────────────────────────────────────────────────────┐
│  4. DESYNCHRONIZE PHILOSOPHERS                      │
│     • Even IDs: sleep 60µs                          │
│     • Odd IDs: calculate thinking time              │
└─────────────┬───────────────────────────────────────┘
              │
              ▼
┌─────────────────────────────────────────────────────┐
│  5. MAIN LOOP (for each philosopher)                │
│     ┌────────────────────────────────────┐          │
│     │  THINKING → EATING → SLEEPING      │          │
│     └────────────────────────────────────┘          │
│     • Acquire forks (lower ID first)                │
│     • Update last_mealtime atomically               │
│     • Sleep for eat/sleep durations                 │
│     • Check meal count & end_simulation flag        │
└─────────────┬───────────────────────────────────────┘
              │
              ▼
┌─────────────────────────────────────────────────────┐
│  6. MONITOR THREAD                                  │
│     • Polls every time_to_die/10 (100-1000µs)       │
│     • Checks: current_time - last_mealtime > die?   │
│     • Sets end_simulation if death detected         │
└─────────────┬───────────────────────────────────────┘
              │
              ▼
┌─────────────────────────────────────────────────────┐
│  7. CLEANUP                                         │
│     • pthread_join() all threads                    │
│     • Destroy mutexes                               │
│     • Free allocated memory                         │
└─────────────────────────────────────────────────────┘
```

---

## Architecture

### Critical Anti-Pattern: Direct Access
```c
// ❌ NEVER DO THIS (causes data races)
if (philo->data->end_simulation) { ... }
time = philo->last_mealtime;
```

### Correct Pattern: Thread-Safe Getters/Setters
```c
// ✅ ALWAYS USE THESE (from getter_setter.c)
bool get_bool(t_mutex *mutex, bool *value);
void set_bool(t_mutex *mutex, bool *dest, bool value);
long get_long(t_mutex *mutex, long *value);
void set_long(t_mutex *mutex, long *dest, long value);
void increase_long(t_mutex *mutex, long *value);
```

**Example Usage:**
```c
// Check if simulation ended
if (get_bool(&philo->data->data_mutex, &philo->data->end_simulation))
    return;

// Update last meal time atomically
set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
```

### Mutex Hierarchy
1. **`data_mutex`**: Protects `end_simulation`, `threads_running_nbr`, `start_simulation`
2. **`philo_mutex`**: Protects `last_mealtime`, `full`, `meals_counter`
3. **`write_mutex`**: Serializes printf output (prevents interleaved text)
4. **`fork_mutex`**: Protects individual fork state

---

## Building & Running

### Prerequisites
- GCC with pthread support
- Make
- Linux/macOS (POSIX-compliant system)

### Compilation
```bash
make        # Build project
make clean  # Remove object files
make fclean # Full clean (removes binary)
make re     # Rebuild from scratch
```

### Usage
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

**Arguments:**
- `number_of_philosophers`: 1-200 (number of philos/forks)
- `time_to_die`: Milliseconds until death if not eating
- `time_to_eat`: Milliseconds to eat (fork holding time)
- `time_to_sleep`: Milliseconds to sleep
- `[optional]` number of meals: Simulation stops when all philos eat this many times

**Examples:**
```bash
# Single philosopher (should die)
./philo 1 800 200 200

# 5 philosophers, 800ms to die, 200ms eat/sleep (should survive)
./philo 5 800 200 200

# 4 philosophers, tight timing, 7 meals per philo
./philo 4 410 200 200 7

# High load test (199 philosophers)
./philo 199 610 200 200 10
```

---

## Testing

### Using the Test Script

The `my_tester.py` script runs comprehensive test suites with multiple iterations:

```bash
# Basic usage (10 iterations per test)
./my_tester.py

# Custom iterations
./my_tester.py --iterations 20

# Specific test suites
./my_tester.py --test mandatory    # Eval sheet tests
./my_tester.py --test uneven-live  # Odd philosopher counts
./my_tester.py --test even-live    # Even philosopher counts
./my_tester.py --test all          # All standard tests
./my_tester.py --test hardcore     # Extended stress tests

# Single test case (20 iterations)
./my_tester.py --single 5 800 200 200 7

# Custom meal count
./my_tester.py --times-to-eat 15
```

### Test Categories

#### 1. **Mandatory Tests** (from eval sheet)
- `1-800-200-200` → Should die (can't acquire 2 forks)
- `5-800-200-200-7` → Should survive (7 meals)
- `4-410-200-200` → Should survive (tight timing)
- `4-310-200-100` → Should die (impossible timing)

#### 2. **Even-Count Tests**
- `4-410-200-200` → Tests desynchronization with 60µs delay
- `50-410-200-200` → Medium load
- `198-610-200-200` → High load (near max threads)

#### 3. **Odd-Count Tests**
- `5-610-200-200` → Tests thinking time formula
- `31-610-200-200` → Medium odd count
- `199-610-200-200` → Max load, odd count

### Interpreting Results

**Success:**
```
✓ 10/10 passed (100%) [PASS]
____________________________________________
```

**Failure (logs saved):**
```
✓ 9/10 passed (90%) [FAIL]
✗ 1 failures saved to fails/*.log
____________________________________________
```

**Failure Log Format** (`fails/199-610-200-200-10_4.log`):
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

# get_next_line

## Overview
get_next_line implements a line-by-line reader for file descriptors in C. The function returns one full line per call, preserving leftover buffer content between calls through static state.

## Tech Stack
- Language: C
- APIs: `read`, `malloc`, `free`
- Configurable compile-time buffer via `BUFFER_SIZE`

## Core Concepts Demonstrated
- Stateful I/O using static storage across function calls
- Chunk-based reading and incremental line reconstruction
- Dynamic linked-list buffering strategy
- Careful cleanup logic for partial leftovers and EOF transitions
- Robust handling of edge cases (empty files, no trailing newline, invalid FD)

## Implementation Notes
- `get_next_line.c` builds and maintains the read buffer list.
- `get_next_line_utils.c` handles newline detection, extraction length, copy, and cleanup.
- The implementation stores read chunks in a custom list, then assembles output lines from that list.

## Project Structure
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

## Compile Example
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c main.c
```

## Why This Project Matters
This project demonstrates practical low-level stream processing and memory-safe state management, which are key skills for systems and backend C development.

# push_swap

## Overview
push_swap is an algorithmic sorting project that orders integers using two stacks and a constrained set of operations. The objective is not only correctness but minimizing the number of operations produced.

## Tech Stack
- Language: C
- Build system: Make
- Dependency: local `libft`
- Validation tooling: `norminette` target integrated in the Makefile

## Core Concepts Demonstrated
- Problem solving under constrained operation sets
- Stack-based algorithm design
- Cost-based move selection and optimization
- Rotation coherence optimization (`rr` / `rrr`) to reduce total instructions
- Robust parsing, duplicate detection, integer bounds checking

## Algorithm Strategy (Current Implementation)
- Parse input from split arguments or a single quoted sequence.
- Handle small cases directly (2 and 3 elements).
- For larger sets:
  - Push elements to helper stack by median-driven strategy.
  - Evaluate move costs to place candidates efficiently.
  - Reinsert elements with coherence-aware rotations.
  - Final rotate to position minimum at top.

## Operations Covered
- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

## Project Structure
- `srcs/algorithm.c`, `srcs/algorithm_helper.c`: sorting and cost logic
- `srcs/operations.c`: primitive stack operations
- `srcs/error_handler.c`: input validation
- `includes/push_swap.h`: data model and API
- `libft/`: utility dependency

## Build & Run
```bash
make
./push_swap 3 2 1
./push_swap "4 2 5 1 3"
```

## Why This Project Matters
This project highlights algorithmic reasoning, optimization trade-offs, and clean decomposition of a non-trivial sorting engine in C.

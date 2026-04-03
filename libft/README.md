# Libft

## Overview
Libft is a custom C utility library developed as a foundational project in the 42 curriculum. It recreates key libc-style functions and adds linked-list helpers used throughout later projects.

This library is designed to be a reusable static archive, compiled once and linked into other applications.

## Tech Stack
- Language: C
- Build system: Make
- Output: static library (`libft.a`)
- Standards: `-Wall -Wextra -Werror`

## Core Concepts Demonstrated
- Manual memory management and defensive allocation patterns
- Reimplementation of standard string and memory routines
- Basic data structure implementation (singly linked list)
- API consistency and modular low-level utilities
- Build automation for library targets (`all`, `clean`, `fclean`, `re`, `bonus`)

## Library Contents
- Character checks and conversions (`ft_is*`, `ft_to*`)
- Memory utilities (`ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_calloc`)
- String handling (`ft_strlen`, `ft_strjoin`, `ft_split`, `ft_substr`, etc.)
- File descriptor output helpers (`ft_putchar_fd`, `ft_putnbr_fd`, etc.)
- Bonus linked-list API (`ft_lstnew`, `ft_lstadd_back`, `ft_lstmap`, ...)

## Project Structure
- `libft.h`: public API
- `ft_*.c`: implementation files grouped by utility domain
- `Makefile`: static archive build rules

## Build
```bash
make
```

## Why This Project Matters
Libft serves as a personal standard library and becomes a dependency for later projects in this workspace (including formatting, parsing, graphics, and concurrency work). It showcases strong C fundamentals and reusable code design.
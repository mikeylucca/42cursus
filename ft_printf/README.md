# ft_printf

## Overview
ft_printf is a custom implementation of the C `printf` function with variadic arguments and a focused subset of format specifiers. It is built as a static library and reused in other projects for formatted output.

## Tech Stack
- Language: C
- Build system: Make
- Dependencies: local `libft`
- Output: static library (`libftprintf.a`)

## Supported Format Specifiers
- `%c` character
- `%s` string
- `%p` pointer
- `%d` / `%i` signed integer
- `%u` unsigned integer
- `%x` / `%X` hexadecimal
- `%%` percent sign

## Core Concepts Demonstrated
- Variadic functions with `stdarg.h`
- Dispatcher-style formatting logic
- Numeric base conversion (decimal and hexadecimal)
- Pointer formatting
- Integration of reusable low-level helpers from Libft

## Project Structure
- `ft_printf.c`: parser loop and specifier dispatch
- `ft_print_*.c`: dedicated handlers per type
- `libftprintf.h`: public interface
- `libft/`: local utility dependency
- `Makefile`: compiles and archives the library

## Build
```bash
make
```

## Why This Project Matters
This project highlights systems-level string formatting, API design, and modular decomposition under strict C constraints.

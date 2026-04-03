# minitalk

## Overview
minitalk is a client-server messaging application built on top of UNIX signals. Messages are serialized bit-by-bit and transmitted between processes using `SIGUSR1` and `SIGUSR2`.

## Tech Stack
- Language: C
- IPC model: UNIX signals (`kill`, `sigaction`, `signal`, `pause`)
- Build system: Make
- Dependency: local `ft_printf` / `libft`

## Core Concepts Demonstrated
- Inter-process communication without sockets or shared memory
- Bit-level encoding/decoding of message payloads
- Signal-driven asynchronous state machines
- Per-bit acknowledgement protocol to improve transmission reliability
- Input validation and process-level error handling

## Protocol Summary
- The client first sends message length in 32 bits.
- Message bytes are then sent bit by bit.
- Server reconstructs bytes and prints the final string.
- Server sends acknowledgements; client waits for completion confirmation.

## Project Structure
- `srcs/client.c`: argument validation, bitwise send logic, ACK tracking
- `srcs/server.c`: bit assembly, dynamic message reconstruction, response signals
- `srcs/error_print.c`: error output helpers
- `includes/minitalk.h`: constants and interfaces
- `Makefile`: builds both `server` and `client`

## Build & Run
```bash
make
./server
./client <server_pid> "Hello from minitalk"
```

## Why This Project Matters
minitalk showcases low-level IPC design, synchronization thinking, and protocol-oriented programming using only core UNIX primitives.

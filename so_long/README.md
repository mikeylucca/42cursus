# so_long

## Overview
so_long is a 2D tile-based game built with MiniLibX. The player navigates a map, collects items, and reaches an exit while respecting strict map validation rules.

## Tech Stack
- Language: C
- Graphics: MiniLibX (X11-based build in current Makefile)
- Build system: Make
- Dependency: local `libft`

## Core Concepts Demonstrated
- Event-driven game loop and keyboard input handling
- Texture loading and tile rendering with XPM assets
- Grid-based movement and game-state updates
- Map parsing and validation pipeline
- Reachability verification with recursive flood-fill
- Memory/resource lifecycle management for MLX objects and maps

## Validation Pipeline
- Enforces `.ber` extension
- Loads and checks map shape and boundaries
- Validates required entities (`P`, `E`, `C`)
- Runs flood-fill to ensure all collectibles and the exit are reachable

## Project Structure
- `sources/parsing.c`, `sources/check_map.c`, `sources/map_init.c`: map loading and rules
- `sources/flood_fill.c`: reachability algorithm
- `sources/start_game.c`, `sources/events_hook.c`, `sources/move.c`: runtime loop and controls
- `sources/tiles.c`, `sources/ft_xpm.c`: rendering pipeline
- `sources/mlx_closing.c`: cleanup routines
- `includes/so_long.h`: shared game structures and interfaces

## Build & Run
```bash
make
./so_long maps/<your_map>.ber
```

## Why This Project Matters
so_long demonstrates practical game-loop architecture, parsing correctness, and graphics resource management in C.

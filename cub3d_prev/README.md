# cub3d (prototype stage)

## Overview
This project is an early raycasting engine prototype inspired by classic pseudo-3D rendering techniques (Wolfenstein-style). It focuses on window management, player movement, and wall projection using MiniLibX.

## Tech Stack
- Language: C
- Graphics: MiniLibX (Linux/X11 variant in current setup)
- Math: trigonometric ray stepping (`sin`, `cos`)
- Build system: Make
- Dependency: local `libft`

## Core Concepts Demonstrated
- Raycasting fundamentals with one ray per screen column
- Field of view projection and wall-slice height calculation
- Per-frame rendering loop with keyboard event hooks
- Player state machine for translation and rotation
- Defensive graphics initialization and cleanup wrappers

## Current Implementation Scope
- Hardcoded map grid for rapid iteration
- Real-time movement (W/A/S/D + arrow rotation)
- Frame-by-frame ray traversal until wall hit
- Basic vertical wall rendering

## Project Structure
- `src/main.c`: initialization, event hooks, main loop
- `src/raycast.c`: ray stepping and wall column drawing
- `src/player/player.c`: input state and movement logic
- `src/map.c`: current map source
- `src/safe_mlx.c`: robust MLX startup/teardown
- `include/cub3d.h`: game structures, constants, interfaces

## Build & Run
```bash
make
./cub3d
```

## Why This Project Matters
Even in prototype form, this project demonstrates graphics pipeline thinking, geometry-driven rendering, and structured low-level application architecture in C.

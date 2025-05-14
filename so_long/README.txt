# So_long Project Documentation

## Overview
This project implements a simple 2D game using the MLX (MiniLibX) graphics library. The game involves a player navigating through a map to collect items and reach an exit while avoiding obstacles.

## Source Files Documentation

### 1. flood_fill.c
This file implements a flood fill algorithm to validate map completion possibility.

Functions:
- `flooder(t_game *game, t_map size, t_character charpos, char filler)`
  - Core flood fill implementation
  - Recursively explores the map in 4 directions (up, down, left, right)
  - Validates reachability of items and exit
  - Parameters:
    - game: Main game structure
    - size: Map dimensions
    - charpos: Current position being checked
    - filler: Character to fill explored positions

- `dam(t_game *game, t_map size, t_character charpos)`
  - Initializes flood fill process
  - Replaces player ('P') and collectibles ('C') with floor ('0')
  - Launches the flood fill algorithm

- `caught_em_all(t_game *game, int itemy, int exity)`
  - Validates if all items and exit are reachable
  - Compares initial count with reached count
  - Returns 0 if validation fails

- `flood_it(t_game *game)`
  - Main entry point for map validation
  - Saves initial item/exit counts
  - Sets up flood fill parameters
  - Returns 1 if map is valid, 0 otherwise

### 2. parsing.c
Handles map file validation and parsing.

Functions:
- `valid_map(char *map, t_game *game)`
  - Validates map file extension (.ber)
  - Checks map existence and format
  - Initializes game structure with map data

- `check_xt(char *map)`
  - Validates file extension
  - Returns 1 if extension is valid (.ber)

### 3. map_init.c
Handles map initialization and loading.

Functions:
- `get_coord(char *mappy, t_game *game)`
  - Determines map dimensions
  - Updates game structure with size information

- `fill_map(char *mappy, t_game *game, char **mapping)`
  - Reads map file line by line
  - Creates 2D array representing the map
  - Validates map format during loading

### 4. struct_init.c
Initializes various game structures.

Functions:
- `init_game_structs(t_game *game)`
  - Master initialization function
  - Calls all sub-initialization functions
  - Returns 1 on success, 0 on failure

- `init_show(t_game *game)`
  - Initializes display-related variables
  - Sets up MLX connection parameters

### 5. events_hook.c
Manages game events and user input.

Functions:
- `kb_input(int keycode, t_game *game)`
  - Handles keyboard input
  - Triggers appropriate movement functions
  - Updates game state based on input

- `motion(int keycode, t_game *game)`
  - Processes movement commands
  - Updates player position
  - Checks for collectibles and exit

### 6. mlx_closing.c
Handles cleanup and program termination.

Functions:
- `map_destroyer(t_game *game)`
  - Frees allocated map memory
  - Cleans up game resources

- `mlx_img_destroyer(t_game *game)`
  - Destroys MLX images
  - Frees image resources

### 7. ft_xpm.c
Manages XPM image loading and handling.

Functions:
- `xpm_load(t_game *game)`
  - Loads game textures from XPM files
  - Initializes game graphics
  - Returns NULL on failure

- `xpm_check(t_game *game)`
  - Validates loaded textures
  - Ensures all required images are loaded

### 8. start_game.c
Handles game initialization and main loop.

Functions:
- `start_game(t_game *game)`
  - Initializes MLX
  - Creates game window
  - Sets up event hooks

- `display_game(t_game *game)`
  - Renders initial game state
  - Displays map and player

### 9. tiles.c
Manages tile rendering and updates.

Functions:
- `load_tiles(t_game *game, int x_map, int y_map)`
  - Renders individual map tiles
  - Handles different tile types (wall, floor, etc.)

- `move_counter(t_game *game, int mover)`
  - Tracks player movement
  - Updates move counter display

### Usage Notes
1. The game requires valid .ber map files
2. Map must be rectangular and enclosed by walls
3. Must contain exactly one player (P), one exit (E), and at least one collectible (C)
4. All collectibles and exit must be reachable

### Error Handling
- Invalid map format triggers appropriate error messages
- Memory allocation failures are handled gracefully
- Graphics initialization errors are reported clearly

### Dependencies
- MiniLibX library
- Standard C libraries
- X11 development libraries

For more detailed information about specific functions or components, refer to the individual source files and their comments.
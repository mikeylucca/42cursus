/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:54 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 16:01:59 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "linux_keys.h"
# include "../mlx/mlx_int.h"
# include "../mlx/mlx.h"

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 480
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 640
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

typedef struct s_tile
{
	int				x_tile;
	int				y_tile;
	char			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}	t_tile;

/*
inventory: would also work for ennemy 
	-> when it "walks" over player, player is added to inventory, end of game
*/

typedef struct s_character
{
	int				x_char;
	int				y_char;
	char			*charac;
	int				move_count;
	int				inventory;
}	t_character;

/*
 elder_index: if hero walked next to elders, then items turn into necronomicon
 no, i don't know how to implement it at the moment
*/

typedef struct s_map
{
	int				x_map;
	int				y_map;
	char			**map;
	int				item_count;
	int				exit_count;
	int				hero_count;
	int				elder_index;
	int				line_size;
	int				col_size;
}	t_map;

typedef struct s_show
{
	void			*mlx_ptr;
	void			*win_ptr;

	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

	int				x_win;
	int				y_win;
}	t_show;

//besoin d'ajouter la mlx ici ?
typedef struct s_game
{
	struct s_character	player;
	struct s_tile		hero;
	struct s_tile		item;
	struct s_tile		exit;
	struct s_tile		wall;
	struct s_tile		floor;
	struct s_map		map;
	struct s_show		show;
}	t_game;

//error.c
int		ft_error(t_game *game, char *err_msg);
int		ft_nomap(t_game *game, char *err_msg);

//utils.c
void	game_over(void);
void	game_under(void);
void	game_over_victory(void);

//struct_init.c
int		init_game_structs(t_game *game);
int		init_show(t_game *game);
int		init_char(t_game *game);
int		init_map(t_game *game);
int		init_tile(t_game *game);

//struct_tiles_init.c
int		init_tile_hero(t_game *game);
int		init_tile_item(t_game *game);
int		init_tile_exit(t_game *game);
int		init_tile_floor(t_game *game);
int		init_tile_wall(t_game *game);

//parsing.c
t_game	*valid_map(char *map, t_game *game);
int		check_xt(char *map);

//map_init.c
t_game	*map_init(char *mappy, t_game *game);
char	**fill_map(char *mappy, t_game *game, char **mapping);
void	get_coord(char *mappy, t_game *game);
void	update_size(t_game *game, int i, int j);

//check_map.c
int		check_map(t_game *game);
int		shape(t_game *game);
int		closed_up(t_game *game);
int		valid_char(t_game *game);
int		check_char(char check, t_game *game);

//elem_pos.c
int		game_ready(t_game *game);
t_game	*elem_pos(t_game *game);
void	exit_pos(int i, int j, t_game *game);
void	player_pos(int i, int j, t_game *game);

//flood_fill.c
int		flood_it(t_game *game);
int		caught_em_all(t_game *game, int itemy, int exity);
void	dam(t_game *game, t_map size, t_character charpos);
void	flooder(t_game *game, t_map size, t_character charpos, char filler);

//start_game.c
int		start_game(t_game *game);
void	display_game(t_game *game);
void	display_map(t_game *game);

//ft_xpm.c
t_game	*xpm_load(t_game *game);
int		xpm_addr(t_game *game);
int		xpm_check(t_game *game);

//events_hook.c
int		kb_input(int keycode, t_game *game);
int		no_event(void *game);
int		closing(t_game *game);
void	motion(int keycode, t_game *game);

//mlx_closing.c
void	map_destroyer(t_game *game);
void	mlx_img_destroyer(t_game *game);
int		mlx_map_destroyer(t_game *game);
void	mlx_destroyer(t_game *game);

//move.c
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

//tiles.c
void	load_tiles(t_game *game, int x_map, int y_map);
void	move_counter(t_game *game, int mover);
void	update_display(t_game *game, int next_y, int next_x);
void	load_exit(t_game *game);
void	check_next_tile(t_game *game, int tile_code, char mod);

#endif

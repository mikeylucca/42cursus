/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:48:00 by misoares          #+#    #+#             */
/*   Updated: 2025/08/06 00:17:51 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "libft.h"
# include "mlx.h"

/* Window settings */
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_TITLE "Cub3D"
# define BLOCK 64
# define DEBUG 0

/* Key codes */
# define ESC_KEY 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define PI 3.14159265359

/* MLX events */
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17

/* Data structures */
typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;

	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;

	char		**map;
}	t_data;

/* Function prototypes */
int		key_hook(int keycode, t_data *data);
int		close_window(t_data *data);
void	init_mlx(t_data *data);
void	cleanup_mlx(t_data *data);
float 	fixed_dist(float x1, float y1, float x2, float y2, t_data *game);
bool 	touch(float px, float py, t_data *game);
float 	distance(float x, float y);
void 	draw_map(t_data *game);
void 	draw_square(int x, int y, int size, int color, t_data *game);
int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
void	move_player(t_player *player);
char	**get_map(void);
void	draw_line(t_player *player, t_data *game, float start_x, int i);
int		draw_loop(t_data *game);
void	clear_image(t_data *data);
void	put_pixel(int x, int y, int color, t_data *data);
void	init_player(t_player *player);

#endif
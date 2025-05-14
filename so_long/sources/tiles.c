/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:52:04 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 16:23:38 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// como que sabe onde meter tuto

void	load_tiles(t_game *game, int x_map, int y_map)
{
	if (game->map.map[y_map][x_map] == '1')
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->wall.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
	else if (game->map.map[y_map][x_map] == '0')
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->floor.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
	else if (game->map.map[y_map][x_map] == 'P')
	{
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->hero.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
		game->map.map[y_map][x_map] = '0';
	}
	else if (game->map.map[y_map][x_map] == 'E')
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->exit.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
	else if (game->map.map[y_map][x_map] == 'C')
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->item.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
}

void	move_counter(t_game *game, int mover)
{
	game->player.move_count += mover;
	if (mover == 1)
		ft_printf("%i steps taken\n", game->player.move_count);
}

void	update_display(t_game *game, int next_y, int next_x)
{
	mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
		game->hero.img, (game->player.x_char + next_x) * TILE_SIZE, \
		(game->player.y_char + next_y) * TILE_SIZE);
	if (game->map.map[game->player.y_char][game->player.x_char] == 'E'
		&& game->player.inventory != game->map.item_count)
	{
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
		game->exit.img, (game->player.x_char) * TILE_SIZE, \
		(game->player.y_char) * TILE_SIZE);
		game->map.map[game->player.y_char][game->player.x_char] = 'E';
	}
	else
	{
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->floor.img, (game->player.x_char) * TILE_SIZE, \
			(game->player.y_char) * TILE_SIZE);
		game->map.map[game->player.y_char][game->player.x_char] = '0';
	}
	game->player.y_char += next_y;
	game->player.x_char += next_x;
	move_counter(game, 1);
}

void	load_exit(t_game *game)
{
	if (game->player.inventory == game->map.item_count)
	{
		mlx_destroy_image(game->show.mlx_ptr, game->exit.img);
		game->exit.img = mlx_xpm_file_to_image(game->show.mlx_ptr, \
			"assets/E_exit_open.xpm", &game->exit.bits_per_pixel, \
			&game->exit.size_line);
		game->exit.addr = mlx_get_data_addr(game->exit.img, \
			&game->exit.bits_per_pixel, &game->exit.size_line, \
			&game->exit.endian);
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->exit.img, (game->exit.x_tile) * TILE_SIZE, \
			(game->exit.y_tile) * TILE_SIZE);
		ft_printf("\nDoor opened\n");
	}
}

void	check_next_tile(t_game *game, int tile_code, char mod)
{
	if (tile_code == 'E' && game->player.inventory == game->map.item_count)
	{
		if (mod == 'u')
			mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
				game->exit.img, (game->player.x_char) * TILE_SIZE, \
				(game->player.y_char - 1) * TILE_SIZE);
		if (mod == 'd')
			mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
				game->exit.img, (game->player.x_char) * TILE_SIZE, \
				(game->player.y_char + 1) * TILE_SIZE);
		if (mod == 'l')
			mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
				game->exit.img, (game->player.x_char - 1) * TILE_SIZE, \
				(game->player.y_char) * TILE_SIZE);
		if (mod == 'r')
			mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
				game->exit.img, (game->player.x_char + 1) * TILE_SIZE, \
				(game->player.y_char) * TILE_SIZE);
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->floor.img, (game->player.x_char) * TILE_SIZE, \
			(game->player.y_char) * TILE_SIZE);
		move_counter(game, 1);
		game_over_victory();
		mlx_map_destroyer(game);
	}
}

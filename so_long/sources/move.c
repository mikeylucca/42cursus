/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:51:41 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 12:10:18 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	check_next_tile(game, game->map.map[game->player.y_char - 1] \
		[game->player.x_char], 'u');
	if (game->map.map[game->player.y_char - 1][game->player.x_char] == '0')
		update_display(game, -1, 0);
	else if (game->map.map[game->player.y_char - 1][game->player.x_char] == 'C')
	{
		game->map.map[game->player.y_char - 1][game->player.x_char] = '0';
		update_display(game, -1, 0);
		game->player.inventory++;
		if (game->player.inventory == game->map.item_count)
			load_exit(game);
	}
	else if (game->map.map[game->player.y_char - 1][game->player.x_char] == 'E'
		&& game->player.inventory != game->map.item_count)
	{
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->hero.img, (game->player.x_char) * TILE_SIZE, \
			(game->player.y_char - 1) * TILE_SIZE);
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->floor.img, (game->player.x_char) * TILE_SIZE, \
			(game->player.y_char) * TILE_SIZE);
		game->player.y_char -= 1;
		move_counter(game, 1);
	}
}

void	move_down(t_game *game)
{
	check_next_tile(game, game->map.map[game->player.y_char + 1] \
		[game->player.x_char], 'd');
	if (game->map.map[game->player.y_char + 1][game->player.x_char] == '0')
		update_display(game, 1, 0);
	else if (game->map.map[game->player.y_char + 1][game->player.x_char] == 'C')
	{
		game->map.map[game->player.y_char + 1][game->player.x_char] = '0';
		update_display(game, 1, 0);
		game->player.inventory++;
		if (game->player.inventory == game->map.item_count)
			load_exit(game);
	}
	else if (game->map.map[game->player.y_char + 1][game->player.x_char] == 'E'
		&& game->player.inventory != game->map.item_count)
	{
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->hero.img, (game->player.x_char) * TILE_SIZE, \
			(game->player.y_char + 1) * TILE_SIZE);
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->floor.img, (game->player.x_char) * TILE_SIZE, \
			(game->player.y_char) * TILE_SIZE);
		game->player.y_char += 1;
		move_counter(game, 1);
	}
}

void	move_left(t_game *game)
{
	check_next_tile(game, game->map.map[game->player.y_char] \
		[game->player.x_char - 1], 'l');
	if (game->map.map[game->player.y_char][game->player.x_char - 1] == '0')
		update_display(game, 0, -1);
	else if (game->map.map[game->player.y_char][game->player.x_char - 1] == 'C')
	{
		game->map.map[game->player.y_char][game->player.x_char - 1] = '0';
		update_display(game, 0, -1);
		game->player.inventory++;
		if (game->player.inventory == game->map.item_count)
			load_exit(game);
	}
	else if (game->map.map[game->player.y_char][game->player.x_char - 1] == 'E'
		&& game->player.inventory != game->map.item_count)
	{
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->hero.img, (game->player.x_char - 1) * TILE_SIZE, \
			(game->player.y_char) * TILE_SIZE);
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->floor.img, (game->player.x_char) * TILE_SIZE, \
			(game->player.y_char) * TILE_SIZE);
		game->player.x_char -= 1;
		move_counter(game, 1);
	}
}

void	move_right(t_game *game)
{
	check_next_tile(game, game->map.map[game->player.y_char] \
		[game->player.x_char + 1], 'r');
	if (game->map.map[game->player.y_char][game->player.x_char + 1] == '0')
		update_display(game, 0, 1);
	else if (game->map.map[game->player.y_char][game->player.x_char + 1] == 'C')
	{
		game->map.map[game->player.y_char][game->player.x_char + 1] = '0';
		update_display(game, 0, 1);
		game->player.inventory++;
		if (game->player.inventory == game->map.item_count)
			load_exit(game);
	}
	else if (game->map.map[game->player.y_char][game->player.x_char + 1] == 'E'
		&& game->player.inventory != game->map.item_count)
	{
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->hero.img, (game->player.x_char + 1) * TILE_SIZE, \
			(game->player.y_char) * TILE_SIZE);
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr, \
			game->floor.img, (game->player.x_char) * TILE_SIZE, \
			(game->player.y_char) * TILE_SIZE);
		game->player.x_char += 1;
		move_counter(game, 1);
	}
}

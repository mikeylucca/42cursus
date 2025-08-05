/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:48:00 by misoares          #+#    #+#             */
/*   Updated: 2025/08/06 00:36:35 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void clear_image(t_data *data)
{
	for(int y = 0; y < WIN_HEIGHT; y++)
		for(int x = 0; x < WIN_WIDTH; x++)
			put_pixel(x, y, 0, data);
}

void	put_pixel(int x, int y, int color, t_data *data)
{
	int idx;
	
	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return;
	idx = y * data->size_line + x * data->bpp / 8;
	data->data[idx] = color & 0xFF;
	data->data[idx + 1] = (color >> 8) & 0xFF;
	data->data[idx + 2] = (color >> 16) & 0xFF;
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	
	/* Initialize data structure */
	ft_bzero(&data, sizeof(t_data));
	
	/* Initialize MLX and create window */
	init_mlx(&data);
	
	/* Initialize player */
	init_player(&data.player);
	
	/* Initialize map */
	data.map = get_map();

	/* Set up event hooks */
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, DESTROY_NOTIFY, 0, close_window, &data);
	mlx_hook(data.win_ptr, 2, 1L<<0, key_press, &data.player);
	mlx_hook(data.win_ptr, 3, 1L<<1, key_release, &data.player);

	mlx_loop_hook(data.mlx_ptr, draw_loop, &data);

	/* Start the MLX loop */
	mlx_loop(data.mlx_ptr);

	return (0);
}
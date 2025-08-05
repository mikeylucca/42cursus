/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:36:25 by misoares          #+#    #+#             */
/*   Updated: 2025/08/06 00:36:41 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Key hook function to handle keyboard input
 * @param keycode: The key code of the pressed key
 * @param data: Pointer to the data structure containing MLX pointers
 * @return: 0 on success
 */
int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

/**
 * Function to close the window and cleanup resources
 * @param data: Pointer to the data structure containing MLX pointers
 * @return: 0 on success
 */
int	close_window(t_data *data)
{
	cleanup_mlx(data);
	exit(0);
	return (0);
}

/**
 * Initialize MLX and create a window
 * @param data: Pointer to the data structure to store MLX pointers
 */
void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		exit(1);
	}

	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!data->win_ptr)
	{
		ft_printf("Error: Failed to create window\n");
		free(data->mlx_ptr);
		exit(1);
	}
	data->img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
	{
		ft_printf("Error: Failed to create img\n");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}

	data->data = mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
	if (!data->data)
	{
		ft_printf("Error: Failed to get image data address\n");
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
}

/**
 * Cleanup MLX resources
 * @param data: Pointer to the data structure containing MLX pointers
 */
void	cleanup_mlx(t_data *data)
{
	if (data->img && data->mlx_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->win_ptr && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
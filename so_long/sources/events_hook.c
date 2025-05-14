/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:37:07 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 12:09:46 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	closing(t_game *game)
{
	mlx_map_destroyer(game);
	return (0);
}

void	motion(int keycode, t_game *game)
{
	if (keycode == K_W || keycode == K_Z || keycode == K_AR_U)
		move_up(game);
	else if (keycode == K_A || keycode == K_Q || keycode == K_AR_L)
		move_left(game);
	else if (keycode == K_S || keycode == K_AR_D)
		move_down(game);
	else if (keycode == K_D || keycode == K_AR_R)
		move_right(game);
}

int	kb_input(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		mlx_map_destroyer(game);
	else
		motion(keycode, game);
	return (0);
}

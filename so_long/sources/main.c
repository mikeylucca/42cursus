/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:51:31 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 12:17:40 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_nomap(game, "Malloc error.");
		game_under();
	}
	if (argc != 2)
	{
		ft_nomap(game, "Usage is:\n./so_long <map.ber>\n");
		game_under();
		return (2);
	}
	if (init_game_structs(game) && valid_map(argv[1], game))
		start_game(game);
	return (0);
}

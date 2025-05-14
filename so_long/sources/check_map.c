/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:51:55 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 20:53:19 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
This function records the numbers of special characters: player, items and exits
If this number is not valid, it displays the appropriate warning
*/

int	check_char(char check, t_game *game)
{
	char	*char_ok;

	char_ok = "01EPC";
	if (check == 'P')
		game->map.hero_count++;
	if (check == 'E')
		game->map.exit_count++;
	if (check == 'C')
		game->map.item_count++;
	if (!ft_strchr(char_ok, check))
	{
		ft_error(game, "This map contains invalid character(s)!\n");
		return (0);
	}
	if (game->map.hero_count > 1 || game->map.exit_count > 1)
	{
		if (game->map.hero_count > 1)
			ft_error(game, "Cannot have more than 1 Player");
		else if (game->map.exit_count > 1)
			ft_error(game, "Cannot have more than 1 Exit");
		return (0);
	}
	return (1);
}

/*
This function goes through the map and verifies every character 
with check_char()
*/
int	valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.col_size - 1)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (!check_char(game->map.map[i][j], game))
				return (0);
			j++;
		}
		i++;
	}
	if (!game_ready(game))
		return (0);
	return (1);
}

/*
This function checks whether the map is fully enclosed with walls
	- checks all of 1st and last line
	- checks first and last character of all intermediate lines
*/

int	closed_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.col_size && j < game->map.line_size)
	{
		while (j < game->map.line_size)
		{
			if (game->map.map[i][0] != '1' ||
				game->map.map[i][game->map.line_size - 1] != '1' ||
				game->map.map[0][j] != '1' ||
				game->map.map[game->map.col_size - 1][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*
This function checks the shape of the map (has to be rectangular)
It does so by checking that all lines have the same length as the first
That's why you can't have any empty line
*/

int	shape(t_game *game)
{
	int	i;
	int	check;

	i = 0;
	check = game->map.line_size;
	while (++i < game->map.col_size - 1)
	{
		if (game->map.map[i][0] == '\n')
			return (0);
		if (!(game->map.map[i][check - 1] && game->map.map[i][check] == '\n'))
			return (0);
	}
	if (game->map.map[i][check] != 0)
	{
		if (game->map.map[i][check] == 'n' && game->map.map[i][check + 1] != 0)
			return (0);
	}
	return (1);
}

/*
This function is a hub to check everything else
*/

int	check_map(t_game *game)
{
	if (!shape(game))
	{
		ft_error(game, "Invalid shape\nPlease provide a rectangular map");
		return (0);
	}
	if (!closed_up(game))
	{
		ft_error(game, "Map cannot be open\nPlease provide a closed map");
		return (0);
	}
	if (!valid_char(game))
		return (0);
	return (1);
}

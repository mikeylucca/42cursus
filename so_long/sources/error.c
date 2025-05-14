/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:18 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:37:27 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
to print errno:
include string.h errno.h
char buf[256]  (or whatever size)
strerror_s(buf, 256, errno);
printf("%s", buf);

*/

#include "../includes/so_long.h"

int	ft_nomap(t_game *game, char *err_msg)
{
	ft_printf("\nError\n");
	ft_printf("%s\n", err_msg);
	ft_printf("\nWell, so long and goodbye\n");
	free(game);
	return (0);
}

int	ft_error(t_game *game, char *err_msg)
{
	ft_printf("\nError!\n\n");
	ft_printf("\n%s", err_msg);
	ft_printf("\nWell, so long and goodbye\n");
	map_destroyer(game);
	free(game);
	return (0);
}

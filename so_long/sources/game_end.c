/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:52:09 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 16:04:52 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_over_banner(void)
{
	ft_printf("\n");
	ft_printf("╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗\n");
	ft_printf("║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝\n");
	ft_printf("╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═\n");
	ft_printf("\n");
}

void	game_under(void)
{
	game_over_banner();
	ft_printf("\n¯\\_(ツ)_/¯\n");
}

void	game_over_victory(void)
{
	ft_printf("\n\nVICTORY ACHIEVED\n");
	game_over_banner();
}

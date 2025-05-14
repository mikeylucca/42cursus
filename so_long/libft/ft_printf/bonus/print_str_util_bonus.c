/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:02:20 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:41:05 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	str_no_dash(t_printf *printed, int len)
{
	while (printed->width > len)
	{
		printed->width--;
		printed->len += write(1, " ", 1);
	}
}

void	str_dash(t_printf *printed, int len)
{
	printed->width -= len;
	while (printed->width > 0)
	{
		printed->len += write (1, " ", 1);
		printed->width--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_util_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:40:12 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:40:29 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	nodash_base(t_printf *printed, int len)
{
	if (printed->zero_p == 1)
	{
		while (printed->width > len)
		{
			printed->len += write(1, "0", 1);
			printed->width--;
		}
	}
	else
	{
		if (printed->prec > len && printed->width > printed->prec)
			printed->width = printed->width - (printed->prec - len);
		while (printed->width > len)
		{
			printed->len += write(1, " ", 1);
			printed->width--;
		}
		while (printed->prec > len)
		{
			printed->len += write(1, "0", 1);
			printed->prec--;
		}
	}
}

void	l_dash(t_printf *printed, int len, unsigned int nbr)
{
	if (len > 0 || printed->width > 0)
	{
		while (printed->prec > len)
		{
			printed->len += write(1, "0", 1);
			printed->prec--;
			printed->width--;
		}
		if (printed->pound == 1 && nbr > 0)
		{
			ft_putstr_fd("0x", 1);
			printed->len += 2;
		}
		if (len > 0)
		{
			lx_hex(printed, nbr);
			printed->len++;
			printed->width -= len;
		}
		while (printed->width > 0)
		{
			printed->len += write (1, " ", 1);
			printed->width--;
		}
	}
}

void	l_print(t_printf *printed, int len, unsigned int nbr)
{
	lx_hex(printed, nbr);
	printed->len++;
	printed->width -= len;
}

void	u_dash(t_printf *printed, int len, unsigned int nbr)
{
	if (len > 0 || printed->width > 0)
	{
		while (printed->prec > len)
		{
			printed->len += write(1, "0", 1);
			printed->prec--;
			printed->width--;
		}
		if (printed->pound == 1 && nbr > 0)
		{
			ft_putstr_fd("0X", 1);
			printed->len += 2;
		}
		if (len > 0)
		{
			ux_hex(printed, nbr);
			printed->len++;
			printed->width -= len;
		}
		while (printed->width > 0)
		{
			printed->len += write (1, " ", 1);
			printed->width--;
		}
	}
}

void	u_print(t_printf *printed, int len, unsigned int nbr)
{
	ux_hex(printed, nbr);
	printed->len++;
	printed->width -= len;
}

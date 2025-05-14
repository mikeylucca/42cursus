/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:41:01 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:41:13 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	nodash(t_printf *printed, int len)
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

void	isdash(t_printf *printed, int len, unsigned int nbr)
{
	if (len > 0 || printed->width > 0)
	{
		while (printed->prec > len)
		{
			printed->len += write(1, "0", 1);
			printed->prec--;
			printed->width--;
		}
		if (len > 0)
		{
			ft_putnbr_unsigned_int(nbr);
			printed->len += len;
			printed->width -= len;
		}
		while (printed->width > 0)
		{
			printed->len += write (1, " ", 1);
			printed->width--;
		}
	}
}

void	print_unsigned(t_printf *printed)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(printed->ap, unsigned int);
	len = flaglen(nbr);
	if (printed->dot > 0 && printed->prec == 0 && nbr == 0)
		len = 0;
	if (printed->width <= printed->prec)
		printed->width = 0;
	if (printed->dash == 0)
	{
		nodash(printed, len);
		if (len > 0)
		{
			ft_putnbr_unsigned_int(nbr);
			printed->len += len;
			printed->width -= len;
		}
	}
	if (printed->dash == 1)
		isdash(printed, len, nbr);
}

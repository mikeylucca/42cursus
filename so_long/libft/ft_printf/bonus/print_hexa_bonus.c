/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:39:57 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:40:16 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	lx_hex(t_printf *printed, unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		lx_hex(printed, n / 16);
		printed->len++;
	}
	ft_putchar_fd(base[n % 16], 1);
}

void	print_hexa_l(t_printf *printed)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(printed->ap, unsigned long long);
	len = hexlen(printed, nbr);
	if (printed->dot > 0 && printed->prec == 0 && nbr == 0)
		len = 0;
	if (printed->width <= printed->prec)
		printed->width = 0;
	if (printed->dash == 0)
	{
		nodash_base(printed, len);
		if (printed->pound == 1 && nbr > 0)
		{
			ft_putstr_fd("0x", 1);
			printed->len += 2;
		}
		if (len > 0)
			l_print(printed, len, nbr);
	}
	if (printed->dash == 1)
		l_dash(printed, len, nbr);
}

void	ux_hex(t_printf *printed, unsigned long long n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n > 15)
	{
		ux_hex(printed, n / 16);
		printed->len++;
	}
	ft_putchar_fd(base[n % 16], 1);
}

void	print_hexa_u(t_printf *printed)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(printed->ap, unsigned long long);
	len = hexlen(printed, nbr);
	if (printed->dot > 0 && printed->prec == 0 && nbr == 0)
		len = 0;
	if (printed->width <= printed->prec)
		printed->width = 0;
	if (printed->dash == 0)
	{
		nodash_base(printed, len);
		if (printed->pound == 1 && nbr > 0)
		{
			ft_putstr_fd("0X", 1);
			printed->len += 2;
		}
		if (len > 0)
			u_print(printed, len, nbr);
	}
	if (printed->dash == 1)
		u_dash(printed, len, nbr);
}

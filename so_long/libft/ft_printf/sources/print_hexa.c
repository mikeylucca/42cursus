/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:39:57 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:52:04 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	print_hexa(t_printf *printed, int hex)
{
	unsigned int	nb;

	nb = va_arg(printed->ap, unsigned long long);
	if (printed->pound == 1)
	{
		if (hex == 'x')
			ft_putstr_fd("0x", 1);
		if (hex == 'X')
			ft_putstr_fd("0X", 1);
		printed->len += 2;
	}
	if (hex == 'X')
		ux_hex(printed, nb);
	if (hex == 'x')
		lx_hex(printed, nb);
	printed->len++;
}

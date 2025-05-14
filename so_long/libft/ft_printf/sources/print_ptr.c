/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:58:42 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:52:10 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_hex(t_printf *printed, unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		ptr_hex(printed, n / 16);
		printed->len++;
	}
	ft_putchar_fd(base[n % 16], 1);
}

void	print_ptr(t_printf *printed)
{
	unsigned long long	nb;

	nb = va_arg(printed->ap, unsigned long long);
	if (nb == 0)
	{
		ft_putstr_fd("(nil)", 1);
		printed->len += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		printed->len += 2;
		ptr_hex(printed, nb);
		printed->len++;
	}
}

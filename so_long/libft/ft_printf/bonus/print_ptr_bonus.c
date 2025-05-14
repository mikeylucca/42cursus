/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:58:42 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:40:38 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ptrlen(unsigned long long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

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

void	ptr_no_dash(t_printf *printed, int len)
{
	while (printed->width > len)
	{
		printed->width--;
		printed->len += write(1, " ", 1);
	}
}

void	ptr_dash(t_printf *printed, int len)
{
	printed->width -= len;
	while (printed->width > 0)
	{
		printed->len += write (1, " ", 1);
		printed->width--;
	}
}

void	print_ptr(t_printf *printed)
{
	unsigned long long	nb;
	int					len;

	nb = va_arg(printed->ap, unsigned long long);
	len = ptrlen(nb) + 2;
	if (nb == 0)
	{
		printed->len += 5;
		len = 5;
	}
	if (printed->dash == 0)
		ptr_no_dash(printed, len);
	if (nb == 0)
		ft_putstr_fd("(nil)", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		printed->len += 2;
		ptr_hex(printed, nb);
		printed->len++;
	}
	if (printed->dash == 1)
		ptr_dash(printed, len);
}

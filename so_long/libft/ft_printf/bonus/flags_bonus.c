/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:52:04 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:39:25 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	flag_conflicts(t_printf *printed, int spec)
{
	if (spec == '0')
		printed->zero_p = 1;
	if (spec == '-')
	{
		printed->dash = 1;
		printed->zero_p = 0;
	}
	if (spec == ' ')
		printed->is_space = 1;
	if (spec == '+')
	{
		printed->plus = 1;
		printed->is_space = 0;
	}
}

void	update_flag(t_printf *printed, int spec)
{
	if (spec == '#')
		printed->pound = 1;
	if (spec == '-' || spec == '0')
		flag_conflicts(printed, spec);
	if (spec == '+' || spec == ' ')
		flag_conflicts(printed, spec);
}

int	hexlen(t_printf *printed, unsigned int nb)
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
	if (printed->pound == 1)
		i += 2;
	return (i);
}

int	flaglen(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_unsigned_int(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr_unsigned_int(nbr / 10);
		nbr %= 10;
	}
	ft_putchar_fd(nbr + 48, 1);
}

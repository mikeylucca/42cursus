/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:28:46 by misoares          #+#    #+#             */
/*   Updated: 2024/05/17 18:15:41 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_print_char(int c)
{
	return (write(1, &c, 1));
}

static int ft_print_str(char *str)
{
	int count;

	count = 0;
	if (!str)
		write(1, "(null)", 6);
	while (*str)
	{
		ft_print_char((int)*str);
		count++;
		str++;
	}
	return (count);
}
int ft_print_digit(long nbr, int base)
{
	int count;
	char *sym;

	count = 0;
	sym = "0123456789abcdef";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-nbr, base) + 1);
	}
	else if (nbr < base)
		return (ft_print_char(sym[nbr]));
	else
	{
		count = ft_print_digit(nbr / base, base);
		return (count + ft_print_char(nbr % base));
	}
	if (nbr == -2147483648)
		return (11);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:40:02 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:40:45 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_long(long long int nb, int fd)
{
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		nb += '0';
		ft_putchar_fd(nb, fd);
	}
}

void	pzero(t_printf *printed, char *sign, int len)
{
	if (*sign == '+' || *sign == '-')
		write(1, sign, 1);
	while (printed->width > len)
	{
		printed->len += write(1, "0", 1);
		printed->width--;
	}
}

long long int	turn_pos(long long int nb)
{
	int				sign;
	long long int	nbr;

	sign = -1;
	nbr = nb;
	nbr = nbr * sign;
	return (nbr);
}

int	signed_len(long long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		nbr = turn_pos(nbr);
	if (nbr == 0)
		i++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void	print_signed(t_printf *printed)
{
	int			snbr;
	int			len;
	char		*sign;
	long long	nbr;

	snbr = va_arg(printed->ap, int);
	nbr = (long)snbr;
	sign = "";
	if (nbr < 0)
		sign = "-";
	len = get_len(printed, nbr);
	if (nbr >= 0)
		sign = plus_sign(printed, sign);
	if (nbr < 0)
		nbr = turn_pos(nbr);
	if (printed->prec > 0 && *sign == '-')
		printed->prec++;
	if (printed->width <= printed->prec)
		printed->width = 0;
	if (printed->dash == 0)
		sig_nodash(printed, sign, len, nbr);
	if (printed->dash == 1)
		signed_dash(printed, sign, len, nbr);
}

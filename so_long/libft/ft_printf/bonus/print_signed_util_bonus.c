/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_util_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:02:55 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:40:52 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	signprint(t_printf *printed, int len, long long nbr)
{
	ft_putnbr_long(nbr, 1);
	printed->len += len;
	printed->width -= len;
}

char	*plus_sign(t_printf *printed, char *sign)
{
	if (printed->plus == 1)
		sign = "+";
	if (printed->is_space == 1)
		sign = " ";
	return (sign);
}

int	get_len(t_printf *printed, long long nbr)
{
	int	len;

	len = 0;
	if (printed->plus == 1 || printed->is_space == 1 || nbr < 0)
		len = 1;
	len += signed_len(nbr);
	if (printed->dot > 0 && printed->prec == 0 && nbr == 0)
		len = 0;
	return (len);
}

void	sig_nodash(t_printf *printed, char *sign, int len, long long nbr)
{
	if (printed->zero_p == 1)
		pzero(printed, sign, len);
	else
	{
		if (printed->prec > len && printed->width > printed->prec)
			printed->width = printed->width - (printed->prec - len);
		while (printed->width > len)
		{
			printed->len += write(1, " ", 1);
			printed->width--;
		}
		if (printed->plus == 1 || *sign == '-' || printed->is_space == 1)
		{
			write(1, sign, 1);
			printed->width--;
		}
		while (printed->prec > len)
		{
			printed->len += write(1, "0", 1);
			printed->prec--;
		}
	}
	if (len > 0)
		signprint(printed, len, nbr);
}

void	signed_dash(t_printf *printed, char *sign, int len, long long nbr)
{
	if (len > 0 || printed->width > 0)
	{
		if (*sign == '+' || *sign == '-')
			write(1, sign, 1);
		while (printed->prec > len)
		{
			printed->len += write(1, "0", 1);
			printed->prec--;
			printed->width--;
		}
		if (len > 0)
			signprint(printed, len, nbr);
		while (printed->width > 0)
		{
			printed->len += write (1, " ", 1);
			printed->width--;
		}
	}
}

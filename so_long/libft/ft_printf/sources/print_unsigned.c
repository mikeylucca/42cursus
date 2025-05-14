/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:41:01 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:52:52 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nlen_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*nbr_decomp_u(char *nbr, unsigned int n, int i)
{
	long long	nagai;

	nagai = (long long)n;
	nbr[i] = '\0';
	i--;
	while (nagai != 0)
	{
		nbr[i] = (nagai % 10) + '0';
		nagai = nagai / 10;
		i--;
	}
	return (nbr);
}

char	*ft_utoa(unsigned int n)
{
	char	*nbr;

	nbr = malloc(sizeof(char) * nlen_u(n) + 1);
	if (nbr == NULL)
		return (NULL);
	if (n == 0)
	{
		nbr[0] = '0';
		nbr[1] = '\0';
	}
	else
		nbr_decomp_u(nbr, n, nlen_u(n));
	return (nbr);
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

void	print_unsigned(t_printf *printed)
{
	unsigned int	nbr;
	char			*nbstr;

	nbr = va_arg(printed->ap, unsigned int);
	ft_putnbr_unsigned_int(nbr);
	nbstr = ft_utoa(nbr);
	printed->len += ft_strlen(nbstr);
	free (nbstr);
}

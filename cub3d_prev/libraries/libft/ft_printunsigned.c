/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:39:11 by misoares          #+#    #+#             */
/*   Updated: 2024/05/18 16:31:12 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printout(unsigned int nb)
{
	if (nb > 9)
		ft_printunsigned(nb / 10);
	if (nb <= 9)
	{
		ft_print_char(nb + 48);
		return ;
	}
	ft_print_char((nb % 10) + 48);
}

int	ft_printunsigned(unsigned int nb)
{
	unsigned int	i;

	printout(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

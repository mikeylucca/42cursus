/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:23:00 by misoares          #+#    #+#             */
/*   Updated: 2024/05/22 16:26:32 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*create_string(unsigned int value, int *strlen)
{
	int				i;
	unsigned int	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = ft_calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	ft_print_hex(unsigned int value, int asc)
{
	unsigned int	tempval;
	int				i;
	int				*iptr;
	char			*printout;

	iptr = &i;
	tempval = value;
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0)
	{
		if ((tempval % 16) < 10)
			printout[i] = (tempval % 16) + '0';
		else
			printout[i] = (tempval % 16) + asc;
		tempval = tempval / 16;
		i--;
	}
	ft_print_str(printout);
	i = ft_strlen(printout);
	free(printout);
	if (value == 0)
		i += ft_print_char('0');
	return (i);
}

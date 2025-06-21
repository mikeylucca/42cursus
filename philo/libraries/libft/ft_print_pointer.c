/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:19:54 by misoares          #+#    #+#             */
/*   Updated: 2025/05/03 18:26:57 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_string(unsigned long value, int *strlen)
{
	int				i;
	unsigned long	temp;
	char			*str;

	i = 0;
	temp = value;
	if (value == 0)
	{
		str = ft_calloc(5, sizeof(char));
		ft_memcpy(str, "(nil)", 5);
		*strlen = 4;
		return (str);
	}
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = ft_calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	ft_print_pointer(unsigned long value)
{
	unsigned long	tempval;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempval = value;
	if (value == 0)
		return (ft_print_str("(nil)"));
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0 && i-- >= 0)
	{
		if ((tempval % 16) < 10)
			printout[i + 1] = (tempval % 16) + '0';
		else
			printout[i + 1] = (tempval % 16) + 'W';
		tempval = tempval / 16;
	}
	i = ft_strlen(printout);
	i += ft_print_str("0x");
	ft_print_str(printout);
	free(printout);
	return (i);
}

/* int	ft_print_pointer(unsigned long value)
{
	int				count;
	char			printout[20];
	unsigned long	tempval;

	count = 0;
	if (value == 0)
		return (ft_print_str("(nil)"));
	tempval = value;
	while (tempval != 0)
	{
		if ((tempval % 16) < 10)
			printout[count] = (tempval % 16) + '0';
		else
			printout[count] = (tempval % 16) + 'W';
		tempval = tempval / 16;
		count++;
	}
	printout[count] = '\0';
	count = ft_strlen(printout);
	count += ft_print_str("0x");
	ft_print_str(printout);
	return (count);
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:47:36 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:30 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	get_prec_len(t_printf *printed, char const *format, int get_spec)
{
	size_t	count;

	count = 0;
	while (ft_isdigit(format[get_spec++]))
		count++;
	printed->dotlen = count + 1;
	printed->forspec += count + 1;
	return (count);
}

void	zero_prec(t_printf *printed, int get_spec)
{
	printed->dot = 2;
	printed->dotlen += 2;
	printed->forspec += 2;
	get_spec += 2;
}

void	get_precision(t_printf *printed, char const *format, int get_spec)
{
	char	*precision;
	size_t	count;

	count = 0;
	get_spec++;
	printed->zero_p = 0;
	if (format[get_spec] == '0')
		zero_prec(printed, get_spec);
	else if (ft_isdigit(format[get_spec]))
	{
		count = get_prec_len(printed, format, get_spec);
		precision = ft_substr(format, get_spec, count);
		printed->prec = ft_atoi(precision);
		get_spec = get_spec + (int)count;
		free(precision);
		printed->dot = 1;
	}
	else
	{
		printed->dot = 2;
		printed->dotlen++;
		printed->forspec++;
	}
}

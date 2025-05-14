/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:53:18 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:51:40 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*struct_init(t_printf *printed)
{
	printed->width = 0;
	printed->pound = 0;
	printed->zero_p = 0;
	printed->dash = 0;
	printed->plus = 0;
	printed->sign = 0;
	printed->zero_digit = 0;
	printed->is_space = 0;
	printed->len = 0;
	printed->percent = 0;
	printed->conv = "";
	return (printed);
}

int	just_print_it(t_printf *printed, char printing)
{
	printed->len += write(1, &printing, 1);
	return (printed->len);
}

int	ft_printf(char const *format, ...)
{
	int			i;
	t_printf	*printed;

	i = 0;
	printed = (t_printf *)malloc(sizeof(t_printf) + 1);
	if (!printed || printed == NULL || printed == 0)
		return (0);
	va_start(printed->ap, format);
	struct_init(printed);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_spec(printed, format, i);
		}
		else
			just_print_it(printed, format[i]);
		i++;
	}
	va_end(printed->ap);
	i = printed->len;
	free (printed);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:53:18 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 16:00:48 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	struct_free(t_printf *printed)
{
	printed->width = 0;
	printed->widlen = 0;
	printed->pound = 0;
	printed->zero_p = 0;
	printed->dash = 0;
	printed->plus = 0;
	printed->dot = 0;
	printed->prec = 0;
	printed->dotlen = 0;
	printed->hexlen = 0;
	printed->is_space = 0;
	printed->forspec = 0;
}

t_printf	*struct_init(t_printf *printed)
{
	printed->width = 0;
	printed->widlen = 0;
	printed->pound = 0;
	printed->zero_p = 0;
	printed->dash = 0;
	printed->plus = 0;
	printed->dot = 0;
	printed->prec = 0;
	printed->dotlen = 0;
	printed->hexlen = 0;
	printed->is_space = 0;
	printed->len = 0;
	printed->forspec = 0;
	printed->conv = "";
	return (printed);
}

int	just_print_it(t_printf *printed, char printing)
{
	printed->len += write(1, &printing, 1);
	return (printed->len);
}

void	checker(t_printf *printed, char const *format, int i, int fo_len)
{
	while (format[i] && i <= (int)fo_len)
	{
		if (format[i] == '%')
		{
			i++;
			check_spec(printed, format, i);
			i += printed->forspec;
		}
		else
			just_print_it(printed, format[i]);
		i++;
		struct_free(printed);
	}
}

int	ft_printf(char const *format, ...)
{
	int			i;
	t_printf	*printed;
	size_t		fo_len;

	i = 0;
	printed = (t_printf *)malloc(sizeof(t_printf) + 1);
	if (!printed || printed == NULL || printed == 0)
		return (0);
	va_start(printed->ap, format);
	struct_init(printed);
	fo_len = ft_strlen(format);
	checker(printed, format, i, fo_len);
	va_end(printed->ap);
	i = printed->len;
	free (printed);
	return (i);
}

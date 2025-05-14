/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:39:37 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:39:17 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	get_wid_len(t_printf *printed, char const *format, int get_spec)
{
	size_t	count;

	count = 0;
	while (ft_isdigit(format[get_spec++]))
		count++;
	printed->widlen = count;
	printed->forspec += count;
	return (count);
}

void	get_width(t_printf *printed, char const *format, int get_spec)
{
	char	*width;
	size_t	count;

	count = 0;
	count = get_wid_len(printed, format, get_spec);
	width = ft_substr(format, get_spec, count);
	printed->width = ft_atoi(width);
	get_spec = get_spec + (int)count;
	free(width);
}

/* void	get_size(t_printf *printed, int spec)
{
	TODO
} */

void	convert_print(t_printf *printed, int spec)
{
	if (spec == '%')
		printed->len += write(1, &spec, 1);
	else if (spec == 'c')
		print_char(printed);
	else if (spec == 's')
		print_str(printed);
	else if (spec == 'd' || spec == 'i')
		print_signed(printed);
	else if (spec == 'u')
		print_unsigned(printed);
	else if (spec == 'x')
		print_hexa_l(printed);
	else if (spec == 'X')
		print_hexa_u(printed);
	else if (spec == 'p')
		print_ptr(printed);
}

void	check_spec(t_printf *printed, char const *format, int get_spec)
{
	const char	*conv_spec;
	const char	*conv_flag;

	conv_spec = "diuxXcsp%%";
	conv_flag = "# +-*0";
	while (ft_strchr(conv_flag, (int)format[get_spec]))
	{
		update_flag(printed, (int)format[get_spec]);
		get_spec++;
		printed->forspec++;
	}
	if (ft_isdigit((int)format[get_spec]))
	{
		get_width(printed, format, get_spec);
		get_spec += printed->widlen;
	}
	if (format[get_spec] == '.')
	{
		get_precision(printed, format, get_spec);
		get_spec += printed->dotlen;
	}
	if (ft_strchr(conv_spec, (int)format[get_spec]))
		convert_print(printed, (int)format[get_spec]);
	else
		write(1, "Unknown conversion", 19);
}

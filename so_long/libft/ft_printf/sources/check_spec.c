/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:39:37 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:51:32 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_print(t_printf *printed, int i)
{
	if (i == '%')
		printed->len += write(1, &i, 1);
	if (i == 'c')
		print_char(printed);
	if (i == 's')
		print_str(printed);
	if (i == 'd' || i == 'i')
		print_signed(printed);
	if (i == 'u')
		print_unsigned(printed);
	if (i == 'x' || i == 'X')
		print_hexa(printed, i);
	if (i == 'p')
		print_ptr(printed);
}

void	check_spec(t_printf *printed, char const *format, int get_spec)
{
	const char	*conv_spec;
	int			spec;

	conv_spec = "diuxXcsp%%";
	spec = (int)format[get_spec];
	if (ft_strchr(conv_spec, spec))
	{
		convert_print(printed, spec);
	}
	else
		write(1, "Unknown conversion", 19);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:39:22 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:40:09 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_char(t_printf *printed)
{
	char	a;

	a = va_arg(printed->ap, int);
	if (printed->dash == 0)
	{
		while (printed->width > 1)
		{
			printed->width--;
			printed->len += write(1, " ", 1);
		}
	}
	printed->len += write(1, &a, 1);
	if (printed->dash == 1)
	{
		while (printed->width > 1)
		{
			printed->len += write (1, " ", 1);
			printed->width--;
		}
	}
}

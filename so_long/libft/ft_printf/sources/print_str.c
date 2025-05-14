/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:40:54 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:52:25 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(t_printf *printed)
{
	char	*print;

	print = va_arg(printed->ap, char *);
	if (!printed || printed == NULL || print == NULL)
	{
		printed->len += write(1, "(null)", 6);
		return (printed->len);
	}
	printed->len += (int)ft_strlen(print);
	ft_putstr_fd(print, 1);
	return (printed->len);
}

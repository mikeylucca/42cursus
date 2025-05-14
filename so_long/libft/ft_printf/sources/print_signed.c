/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:40:02 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:52:18 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_signed(t_printf *printed)
{
	int		nbr;
	char	*nbstr;

	nbr = va_arg(printed->ap, int);
	ft_putnbr_fd(nbr, 1);
	nbstr = ft_itoa((int)nbr);
	printed->len += ft_strlen(nbstr);
	free (nbstr);
}

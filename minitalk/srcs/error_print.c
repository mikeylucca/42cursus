/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:25:38 by misoares          #+#    #+#             */
/*   Updated: 2025/05/06 19:37:51 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	error_print(int i)
{
	if (i == 1)
	{
		ft_printf("String cannot be empty\n");
		return (1);
	}
	else if (i == 2)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	else if (i == 3)
	{
		ft_printf("Usage is PID + Message\n");
		return (1);
	}
	else
		return (0);
}

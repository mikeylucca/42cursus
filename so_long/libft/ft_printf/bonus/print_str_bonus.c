/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:40:54 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:40:59 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	str_null(t_printf *printed, char *print)
{
	int	strnull;

	strnull = 0;
	if (!printed || printed == NULL || !print)
		strnull = 1;
	else
		strnull = 0;
	return (strnull);
}

char	*check_dot(t_printf *printed, char *print, int strnull)
{
	char	*dotprint;

	if (printed->dot == 1)
	{
		if (strnull == 1 && printed->prec < 6)
			printed->dot = 2;
		else if (strnull == 1 && printed->prec >= 6)
			printed->dot = 0;
		else
		{
			dotprint = ft_substr(print, 0, printed->prec);
			print = ft_strdup(dotprint);
			free(dotprint);
		}
	}
	if (printed->dot == 2)
		print = "\0";
	return (print);
}

char	*is_str_null(t_printf *printed, int strnull, char *print)
{
	if (strnull == 1 && printed->dot == 0)
		write(1, "(null)", 6);
	if (printed->dot > 0 && strnull == 1)
		print = "\0";
	else
		ft_putstr_fd(print, 1);
	return (print);
}

int	get_str_len(t_printf *printed, char *print, int strnull)
{
	int	len;

	len = 0;
	if (printed->dot == 1 && strnull == 1)
		len = printed->prec;
	else if (printed->dot == 2)
		len = 0;
	else if (strnull == 1)
		len = 6;
	else
	{
		len = ft_strlen(print);
		printed->dotlen = len;
	}
	return (len);
}

void	print_str(t_printf *printed)
{
	char	*print;
	int		len;
	int		strnull;

	print = va_arg(printed->ap, char *);
	len = 0;
	strnull = str_null(printed, print);
	if (printed->dot > 0)
		print = check_dot(printed, print, strnull);
	len = get_str_len(printed, print, strnull);
	if (printed->dash == 0)
		str_no_dash(printed, len);
	print = is_str_null(printed, strnull, print);
	printed->len += len;
	if (printed->dash == 1)
		str_dash(printed, len);
	if (printed->dot == 1)
		free(print);
}

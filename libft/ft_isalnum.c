/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:11:56 by misoares          #+#    #+#             */
/*   Updated: 2024/04/11 11:44:47 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(int c)
{
	if(c >= 48 && c <= 122)
	{
		return (1);
	}
	else
		return (0);
}

/* #include <stdio.h>

int main(void)
{
	char c;
	c = '@';

	printf("%d", ft_isalnum(c));
	return 0;
} */
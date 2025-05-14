/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:36:24 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	else
		return (c);
}

/*
int	main(void)
{
	int	test;

	test = ';';
	printf(";=59=%i\n", ft_tolower(test));
	test = 'A';
	printf("A=65=%i\n", ft_tolower(test));
	test = 'Z';
	printf("Z=90=%i\n", ft_tolower(test));
	test = 'a';
	printf("a=97=%i\n", ft_tolower(test));
	test = 'z';
	printf("z=122=%i\n", ft_tolower(test));
	test = '0';
	printf("0=48=%i\n", ft_tolower(test));
	test = '|';
	printf("|=124=%i\n", ft_tolower(test));
}
*/

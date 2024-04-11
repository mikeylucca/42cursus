/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:06:01 by misoares          #+#    #+#             */
/*   Updated: 2024/04/08 15:16:51 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(int c)
{
	if(c >= 48 && c <= 57)
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
	c = 'D';

	printf("%d", ft_isdigit(c));
	return 0;
} */
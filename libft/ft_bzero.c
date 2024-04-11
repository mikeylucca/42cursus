/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:25:39 by misoares          #+#    #+#             */
/*   Updated: 2024/04/11 14:30:30 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* void ft_bzero(void *s, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;

	while (i < n)
	{
		ptr[i++] = ft_memset()
	}
} */

void *ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;

	while (i < n)
		ptr[i++] = (unsigned char)c;
	return (0);
}

void ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int main(void)
{
	char str[50] = "Testing this string as example";
	ft_bzero(str + 3, 8*sizeof(char));

	printf("%s", str);

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:03:50 by misoares          #+#    #+#             */
/*   Updated: 2024/05/10 20:00:44 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>  */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	ds = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (!sr && !ds)
		return (NULL);
	if (sr < ds)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ds[i] = sr[i];
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			ds[i] = sr[i];
	}
	return (dest);
}

/* int main(void)
{
	const char *string = "Test string";
	const char *string2 = "Test string";

	char *src = (char *)malloc(strlen(string) + 10);
	char *src2 = (char *)malloc(strlen(string2) + 1);

	strcpy(src, string);
	strcpy(src2, string2);

	char dest[50];
	char dest2[50];

	memmove(src2, src2 + 3, strlen(src2 + 3) + 1);
	printf("original memmove: |%s|\n", src2);

	ft_memmove(src, src + 3, strlen(src + 3) + 1);
	printf("ft_memmove: |%s|\n", src);

	free(src);
	free(src2);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:12:52 by misoares          #+#    #+#             */
/*   Updated: 2024/04/27 12:57:37 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *sr;
	unsigned char *ds;
	size_t i;

	i = 0;
	sr = (unsigned char *)src;
	ds = (unsigned char *)dest;

	if (!sr || !ds)
		return (NULL);

	while (i < n)
	{
		*(sr + i) = *(ds + i);
		i++;
	}
	return (ds);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:03:50 by misoares          #+#    #+#             */
/*   Updated: 2024/04/27 16:01:50 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		while (++i <= n)
			ds[n - i] = sr[n - i];
	}
	else
		while (n-- > 0)
			*(ds++) = *(sr++);
	return (ds);
}

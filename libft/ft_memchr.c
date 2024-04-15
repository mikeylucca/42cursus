/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:29:25 by misoares          #+#    #+#             */
/*   Updated: 2024/04/15 14:38:36 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*s_cp;

	s_cp = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (s_cp[i] == (unsigned char)c)
			return (s_cp + i);
		i++;
	}
	return (NULL);
}
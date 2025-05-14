/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:35:46 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*memarea;
	unsigned char		carac;

	memarea = (const unsigned char *) s;
	carac = (unsigned char)c;
	while (n > 0)
	{
		if (*memarea == carac)
			return ((void *)memarea);
		n--;
		memarea++;
	}
	return (NULL);
}
/*
int		main()
{
	void *s = "bonjour";
	size_t	i = 4;
	int	c = 98;
	
	ft_memchr(s, c, i);
	return (0);
}
*/

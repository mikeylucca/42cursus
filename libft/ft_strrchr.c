/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:19:11 by misoares          #+#    #+#             */
/*   Updated: 2024/04/27 15:52:57 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	position_c;

	position_c = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			position_c = i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if (position_c == -1)
		return (NULL);
	return ((char *)s + position_c);
}

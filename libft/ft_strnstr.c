/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:49:09 by misoares          #+#    #+#             */
/*   Updated: 2024/04/27 15:52:25 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	y;
	size_t	i;
	size_t	j;

	i = 0;
	y = 0;
	j = 0;
	if (needle[0] == '\0')
		return (NULL);
	while (haystack[i] && y < len)
	{
		while (haystack[i] && haystack[i] == needle[j] && (y + i) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i - j);
			i++;
			j++;
		}
		i = 0;
		j = 0;
		haystack++;
		y++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:49:09 by misoares          #+#    #+#             */
/*   Updated: 2024/05/10 13:49:34 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	y;
	size_t	i;

	y = -1;
	if (!needle)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && ++y < len)
	{
		i = 0;
		while (haystack[i] && haystack[i] == needle[i] && (y + i) < len)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

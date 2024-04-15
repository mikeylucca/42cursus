/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:36:40 by misoares          #+#    #+#             */
/*   Updated: 2024/04/15 13:45:19 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if (dstsize == 0)
    {
        while (src[i])
            i++;
        return (i);
    }
    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    if (i < dstsize)
        dst[i] = '\0';
    while (src[i] != '\0')
        i++;
    return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:11:43 by misoares          #+#    #+#             */
/*   Updated: 2024/04/15 14:18:06 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != c)
    {
        if (s[i] == '\0')
            return (NULL);
        i++;
    }
    return ((char *)s + i);
}
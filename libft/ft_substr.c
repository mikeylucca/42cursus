/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:26:19 by misoares          #+#    #+#             */
/*   Updated: 2024/04/17 19:34:01 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *ret;

    if (!s)
        return (0);
    if (ft_strlen(s) < start)
        len = 0;
    if (ft_strlen(s + start) < len)
        len = ft_strlen(s + start);
    ret = malloc(sizeof(char) * (len + 1));
    if (!ret)
        return (0);
    ft_strlcpy(ret, s + start, len + 1);
    return (ret);
}
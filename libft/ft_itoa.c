/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:10:01 by misoares          #+#    #+#             */
/*   Updated: 2024/04/21 09:31:39 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  len_num(int n)
{
    int len;

    len = 1;
    if (n < 0)
    {
        len++;
        if (n = -2147483648)
        {
            return (11);
        }
        else
            n *= -1;
    }
    while (n >= 10)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int n)
{
    char *str_n;
    int len;
    int i;
    long n1;
    int y;

    i = 0;
    y = 1;
    n1 = (long)n;
    len = len_num (n1);
    if (!(str_n = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    if (n1 < 0)
    {
        str_n[i++] = '-';
        n1 *= -1;
    }
    while (len - y >= i)
    {
        str_n[len - y] = ('0' + n1 % 10);
        n1 /= 10;
        y++;
    }
    str_n[len] = '\0';
    return (str_n);
}

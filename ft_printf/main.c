/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:19:11 by misoares          #+#    #+#             */
/*   Updated: 2024/05/22 17:52:33 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main(void) 
{
    char c = 'A';
    char *s = "Hello";
    int i = 42;
    unsigned int u = 123;
    void *p = &i;
    int x = 0x123;
    int X = 0x123;

    int ft_count = ft_printf("Char: %c, String: %s, Int: %d, Unsigned: %u, Pointer: %p, Hex: %x, Hex uppercase: %X, percentage: %%, NULL pointer %p .\n", c, s, i, u, p, x, X, NULL);
    int std_count = printf("Char: %c, String: %s, Int: %d, Unsigned: %u, Pointer: %p, Hex: %x, Hex uppercase: %X, percentage: %%, NULL pointer %p .\n", c, s, i, u, p, x, X, NULL);

    printf("ft_printf returned %d, printf returned %d\n", ft_count, std_count);

    return 0;
}

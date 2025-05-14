/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:35:59 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:48:02 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*memarea;

	memarea = (unsigned char *) s;
	while (n > 0)
	{
		*memarea = (unsigned char) c;
		memarea++;
		n--;
	}
	return (s);
}
/*
int main()
{
    char str[50] = "Aticleworld is a programming Blog.";
    printf("\nBefore memset(): %s\n\n", str);
    // Fill 6 characters starting from str[11] with '*'
//    memset(str + 11, '*', 6);
    ft_memset(str + 11, '*', 6);
    printf("After memset(): %s\n\n", str);
    return 0;
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:35:56 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*castsrc;
	char		*castdest;
	size_t		i;

	i = 0;
	castsrc = src;
	castdest = dest;
	if (castdest < castsrc)
	{
		while (i < n)
		{
			castdest[i] = castsrc[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			castdest[n] = castsrc[n];
	return (castdest);
}

/*
int main()
{
    char str1[] = "Geeks"; // Array of size 100
    char str2[] = "Quiz"; // Array of size 5
 
    puts("str1 before memmove ");
    puts(str1);
 
    // Copies contents of str2 to sr1 
	memmove(str1, str2, sizeof(str2));
//	ft_memmove(str1, str2, sizeof(str2));
 
    puts("\nstr1 after memmove ");
    puts(str1);
 
    return 0;
}
*/

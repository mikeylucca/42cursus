/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:11:27 by misoares          #+#    #+#             */
/*   Updated: 2024/04/28 19:33:49 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	u1;
	unsigned char	u2;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
		{
			u1 = (unsigned char)s1[i];
			u2 = (unsigned char)s2[i];
			return (u1 - u2);
		}
		i++;
	}
	return (0);
}

/* int main(void)
{
	char *str = "string test";
	char *str2 = "string tesu";

	printf("original strncmp: %i\n", strncmp(str, str2, 11));
	printf("my strncmp: %i\n", ft_strncmp(str, str2, 11));
} */

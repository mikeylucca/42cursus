/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:36:34 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copie;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	copie = malloc(ft_strlen(s) + 1);
	if (copie == NULL)
		return (NULL);
	while (s[i])
	{
		copie[i] = s[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}

/*
int	main()
{
	char	str1[] = "hello there";
	char	*target = ft_strdup(str1);
//	char	*target = strdup(str1);

	printf("%s\n", target);
	free(ft_strdup(str1));
	return (0);
}
*/
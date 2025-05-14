/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:36:58 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 14:49:26 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = -1;
	j = -1;
	joined = malloc((sizeof(char) * lens1) + (sizeof(char) * lens2) + 1);
	if (joined == NULL)
		return (NULL);
	while (s1 && i++ < lens1 - 1)
		joined[i] = s1[i];
	while (s2 && j++ < lens2 - 1)
		joined[i++] = s2[j];
	joined[i] = '\0';
	return (joined);
}

/* int	main(void)
{
	char	str1[] = "lorem ipsum";
	char	str2[] = "dolor sit amet";

	printf("%s", ft_strjoin(str1, str2));
	return (0);
}
*/

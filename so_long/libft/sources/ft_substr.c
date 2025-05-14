/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:37:06 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*copie;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	copie = malloc(sizeof(char) * (len + 1));
	if (!copie)
		return (NULL);
	while (len-- > 0 && s[start + i])
	{
		copie[i] = s[start + i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}

/* int	main(void)
{
	const char	str[] = "Tripouille";
	char	*subbb;

	printf("%s\n", str);
	subbb = ft_substr(str, 100, 1);
	printf("et donc=%s", subbb);
	printf("\ntaille=%lu", ft_strlen(subbb));
	free(subbb);
} */

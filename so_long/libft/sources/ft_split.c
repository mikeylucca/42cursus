/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:36:53 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chk_item_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (*s == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*splitter(const char *s, int init, int end)
{
	char	*item;
	int		i;

	item = malloc(sizeof(char) * (end - init) + 1);
	if (!item)
		return (NULL);
	i = 0;
	while (end > init)
	{
		item[i++] = s[init++];
	}
	item[i] = '\0';
	return (item);
}

char	**ft_split(char const *s, char c)
{
	char		**splitted;
	size_t		i;
	size_t		j;
	int			k;

	i = 0;
	j = 0;
	k = -1;
	if (s == NULL)
		return (NULL);
	splitted = malloc(sizeof(char *) * (chk_item_count(s, c) + 1));
	if (!splitted)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			splitted[j++] = splitter(s, k, i);
			k = -1;
		}
		i++;
	}
	return (splitted[j] = NULL, splitted);
}

/* int	main(void)
{
	char const	*str1 = NULL;
	char separate = '\t';
	char	**copie;
	size_t	i = 0;

	copie = ft_split(str1, separate);
	while (copie[i] != NULL)
	{
		printf("%s", copie[i]);
		i++;
	}
	ft_putnbr_fd(i, 0);
	return (0);
} */

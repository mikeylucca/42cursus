/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:27:14 by misoares          #+#    #+#             */
/*   Updated: 2024/05/13 15:43:47 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	get_wordlen(const char *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	return (word_len);
}

static char	**free_all(char **lst)
{
	int	i;

	i = 0;
	while (lst[i] != NULL)
		free(lst[i++]);
	free(lst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	wordlen;
	int		i;

	if (!s)
		return (NULL);
	lst = (char **)malloc((countword(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			wordlen = get_wordlen(s, c);
			lst[i] = ft_substr(s, 0, wordlen);
			if (lst[i++] == NULL)
				return (free_all(lst));
			s += wordlen; 
		}
	}
	lst[i] = NULL;
	return (lst);
}

/* int	main(void) -- Tests ft_split
{
	int		i;
	char	*str;
	char	**strss;

	str = "Lorem, ipsum, dolor, sit amet,;
	strss = ft_split(str, ',');
	i = -1;
	while (strss[++i])
	{
		printf("%s\n", strss[i]);
		free(strss[i]);
	}
	free(strss);
	return (0);
} */
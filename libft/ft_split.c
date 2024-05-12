/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:27:14 by misoares          #+#    #+#             */
/*   Updated: 2024/05/12 18:20:36 by misoares         ###   ########.fr       */
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
			lst[i++] = ft_substr(s, 0, wordlen);
			s += wordlen; 
		}
	}
	lst[i] = NULL;
	return (lst);
}

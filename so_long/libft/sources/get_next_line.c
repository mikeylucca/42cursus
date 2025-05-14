/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:22:24 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *joiner, char *backer, ssize_t reader)
{
	char	*str;
	int		len;
	int		j;

	if (joiner == NULL)
		return (backer);
	len = ft_strlen(joiner);
	j = -1;
	str = (char *)malloc(sizeof(*str) * (len + reader) + 1);
	if (!str)
		return (free(joiner), NULL);
	while (joiner && joiner[++j])
		str[j] = joiner[j];
	j = -1;
	while (backer && backer[++j])
		str[len + j] = backer[j];
	str[len + j] = '\0';
	free(joiner);
	return (str);
}

int	get_read(int fd, char *backer, char **joiner)
{
	char	*join;
	int		reader;

	join = *joiner;
	reader = read(fd, backer, BUFFER_SIZE);
	if (reader == -1)
		return (1);
	if (reader == 0)
		return (2);
	backer[reader] = '\0';
	if (join == NULL)
	{
		join = ft_strdup(backer);
		if (join == NULL)
			return (1);
	}
	else
	{
		join = ft_strjoin_gnl(join, backer, reader);
		if (join == NULL)
			return (1);
	}
	*joiner = join;
	return (0);
}

void	unget_backer(char *backer, char *joiner)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (joiner[i] && joiner[i] != '\n')
		i++;
	if (joiner[i] == '\n')
		i++;
	while (joiner[i])
	{
		backer[j] = joiner[i];
		joiner[i] = '\0';
		i++;
		j++;
	}
}

char	*get_next_line(int fd)
{
	static char	backer[BUFFER_SIZE + 1];
	char		*joiner;
	int			mark;

	mark = 0;
	joiner = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	if (*backer)
	{
		joiner = ft_strdup(backer);
		if (joiner == NULL)
			return (NULL);
	}
	while (ft_strchr(joiner, '\n') == NULL && mark == 0)
		mark = get_read(fd, backer, &joiner);
	if (mark == 1)
		return (NULL);
	ft_bzero(backer, ft_strlen(backer));
	if (mark == 0)
		unget_backer(backer, joiner);
	return (joiner);
}

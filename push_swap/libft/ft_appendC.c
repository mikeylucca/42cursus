/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:22:00 by misoares          #+#    #+#             */
/*   Updated: 2025/01/20 02:14:16 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_appendC(char *start, char c)
{
	size_t	i;
	char	*tmp;

	tmp = malloc(ft_strlen(start) + 2);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (start[i] != '\0')
	{
		tmp[i] = start[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(start);
	return (tmp);
}

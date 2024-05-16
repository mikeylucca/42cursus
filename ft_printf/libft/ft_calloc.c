/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:06:13 by misoares          #+#    #+#             */
/*   Updated: 2024/05/10 14:08:15 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t blocks, size_t size)
{
	void	*tab;
	size_t	allocsize;

	allocsize = blocks * size;
	if (allocsize && size && allocsize > (UINT_MAX / size))
		return (NULL);
	tab = (void *)malloc(allocsize);
	if (!tab)
		return (NULL);
	ft_bzero(tab, blocks * size);
	return (tab);
}

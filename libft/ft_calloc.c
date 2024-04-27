/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:06:13 by misoares          #+#    #+#             */
/*   Updated: 2024/04/27 15:29:20 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t blocks, size_t size)
{
	char	*tab;

	tab = (char *)malloc(blocks * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, blocks * size);
	return (tab);
}

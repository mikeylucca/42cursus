/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:56:05 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*elem;
	int		i;

	i = 0;
	elem = lst;
	while (elem != NULL)
	{
		elem = elem -> next;
		i++;
	}
	return (i);
}

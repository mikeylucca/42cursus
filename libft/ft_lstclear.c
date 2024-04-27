/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:43:23 by misoares          #+#    #+#             */
/*   Updated: 2024/04/27 15:30:09 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*current;

	if (lst && del)
	{
		tmp = *lst;
		while (tmp)
		{
			current = tmp;
			del(tmp->content);
			free(tmp);
			tmp = current->next;
		}
		*lst = NULL;
	}
}

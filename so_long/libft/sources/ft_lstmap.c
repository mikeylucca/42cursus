/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:55:59 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mappy;
	t_list	*mapped;

	mappy = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		mapped = ft_lstnew(f(lst->content));
		if (!(mapped))
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&mappy, mapped);
		lst = lst->next;
	}
	return (mappy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:56:20 by misoares          #+#    #+#             */
/*   Updated: 2024/05/12 19:30:10 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			del(set);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* int main (void)
{
	t_list *head = NULL;
	t_list *newlst;
	t_list	*current;

	

	t_list *node1 = ft_lstnew(ft_strdup("Node 1"));
	t_list *node2 = ft_lstnew(ft_strdup("Node 2"));
	t_list *node3 = ft_lstnew(ft_strdup("Node 3"));
	

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);


	printf("After adding the new nodes: ");
	print_list(head);
	printf("List size: %i", ft_lstsize(head));
	printf("\n");
 
	t_list *newcontent = ft_lstnew(ft_strdup("New node added in front"));
	ft_lstadd_front(&head, newcontent);
	printf("After adding the one new node: \n");
	print_list(head);
	printf("\n");
	printf("New list size: %i", ft_lstsize(head));
	printf("\n");
	
	printf("Last node: ");
	print_list(ft_lstlast(head));
	printf("\n");

	newlst = ft_lstmap(head, lst_toupper, free);
	printf("New list with lstmap:");
	printf("\n");
	print_list(newlst);
	printf("\n");

	ft_lstclear(&head, free);
	while (newlst)
	{
		current = newlst;
		newlst = (newlst)->next;
		free(current);
	}
	newlst = NULL;
	return (0);
} */
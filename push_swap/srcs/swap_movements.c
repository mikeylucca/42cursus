/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:37:28 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 19:00:10 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **head)
{
	int	len;

	len = stack_size(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack	**a, bool flag)
{
	swap(a);
	if (!flag)
	{
	ft_putstr_fd("sa\n", 2);
		/* code */
	}
	
}

void	sb(t_stack **b, bool flag)
{
	swap(b);
	if (!flag)
	{
	ft_putstr_fd("sb\n", 2);
		/* code */
	}
	
}

void	ss(t_stack **a, t_stack **b, bool flag)
{
	swap(a);
	swap(b);
	if (!flag)
	{
		ft_putstr_fd("ss\n", 2);
	}
}
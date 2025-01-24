/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:23:10 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 14:48:40 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Push a node to the top from src to dest
 * 🚨 attention If stack empty (i.e. NULL)
*/
static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack **a, t_stack **b, bool flag)
{
	push(a, b);
	if (!flag)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a, bool flag)
{
	push(b, a);
	if (!flag)
		ft_putstr_fd("pb\n", 1);
}
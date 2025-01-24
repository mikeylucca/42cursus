/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:42:43 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 18:49:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	int				len;

	len = stack_size(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}	

void	ra(t_stack **a, bool flag)
{
	rotate(a);
	if (!flag)
		ft_putstr_fd("ra\n", 2);
}

void	rb(t_stack **b, bool flag)
{
	rotate(b);
	if (!flag)
		ft_putstr_fd("rb\n", 2);
}

void	rr(t_stack **a, t_stack **b, bool flag)
{
	rotate(a);
	rotate(b);
	if (!flag)
		ft_putstr_fd("rr\n", 2);
}
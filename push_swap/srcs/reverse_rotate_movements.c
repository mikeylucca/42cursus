/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:49:13 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 18:49:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int				len;

	len = stack_size(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool flag)
{
	reverse_rotate(a);
	if (!flag)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, bool flag)
{
	reverse_rotate(b);
	if (!flag)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b, bool flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!flag)
		ft_putstr_fd("rrr\n", 1);
}
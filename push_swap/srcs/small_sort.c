/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:07:45 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 18:49:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack	*find_highest(t_stack *stack)
{
	int				highest;
	t_stack	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	highest_node = NULL; // Initialize highest_node
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

/*
 * When i have 3 nodes, easy to sort
 * 	~If the 1* is the biggest, ra (biggestto bottom)
 * 	~If the 2* is the biggest, rra (biggest to bottom)
 * 	~Now i have forcefully the Biggest at the bottom
 * 		so i just chek 1° and 2°
*/
void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (highest_node == NULL) // Check if highest_node is NULL
		return; // Early return if the stack is empty
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

/*
 * Handle input 5
*/
void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}

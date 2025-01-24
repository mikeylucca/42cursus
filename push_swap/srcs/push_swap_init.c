/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:40:29 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 18:49:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Set the current position of every node 
 * in the current state-configuration
*/
void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = stack_size(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR 
 *  With this function every node in b gets its target node in a
*/
static void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*
 * Set the prices to push the node
 * from b -> a
 * The price checks for the relative positions in the stack
 * for every node, setting the respective price
*/
void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

/*
 * Flag the cheapest node in the current
 * stacks configurations
*/
void	set_cheapest(t_stack *b)
{
	long			best_match_value;
	t_stack	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	best_match_node = NULL; // Initialize to NULL
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	if (best_match_node != NULL) // Check if best_match_node is not NULL
		best_match_node->cheapest = true;
}

/*
 * All the necessary values to make the push
 * 		~Relative Positions
 * 		~Target node, the b node to make emerge
 * 		~Price for every configuration
 * 		~Cheapest in the current configuration
*/
void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

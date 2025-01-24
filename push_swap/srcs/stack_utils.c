/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:04:48 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 18:49:13 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

/*
 * Search for the last node and append 
 * 🚨 Pay attention if the stack empty?
*/
void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/*
 * Find the smallest value node
*/
t_stack	*find_smallest(t_stack *stack)
{
	long			smallest;
	t_stack	*smallest_node;
	
	smallest_node = NULL; // Initialize to NULL
	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

/*
 * Return the cheapest node 
 * that is already flagged
*/
t_stack	*return_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
int	stack_size(t_stack *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
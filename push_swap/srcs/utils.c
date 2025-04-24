/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:40:29 by misoares          #+#    #+#             */
/*   Updated: 2025/04/21 10:04:05 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	get_start_stack(t_elem *stack)
{
	int	first;

	first = 0;
	while (stack[first].filled != 1)
		first++;
	if (stack[first].index == -1)
		first--;
	return (first);
}

int	get_end_stack(t_elem *stack)
{
	int	end;

	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	return (end);
}

int	is_median(t_elem *stack, int num)
{
	int	start;
	int	end;
	int	higher;
	int	lower;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	higher = 0;
	lower = 0;
	while (start <= end)
	{
		if (stack[start].num > num)
			higher++;
		else if (stack[start].num < num)
			lower++;
		start++;
	}
	if ((higher - lower) >= -1 && (higher - lower) <= 1)
		return (1);
	return (0);
}

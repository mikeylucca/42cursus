/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:11:45 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 14:53:34 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Ad hoc function to free the 2D array
 * created with the ft_split function
 * ATTENTION
 * You have to start from -1 
*/
void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

/*
 * Ad hoc function to free a stack
*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/*
 * Matrix starts from -1
 * because i artificially made Up
 * equal to argv
*/
void	error_free(t_stack **a, char **argv, bool flag)
{
	free_stack(a);
	if (flag)
		free_matrix(argv);
	ft_putstr_fd("Error", 2);
	exit(1);
}

/*
 * Check if there are some syntactical mistakes
*/
int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

/*
 * Loop into the stack for some repetition
*/
int	error_repetition(t_stack *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

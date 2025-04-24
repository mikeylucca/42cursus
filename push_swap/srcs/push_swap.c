/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:37:27 by misoares          #+#    #+#             */
/*   Updated: 2025/04/21 09:44:52 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	choose_resolve(t_elem *stack_a, t_elem *stack_b, int argc)
{
	if (argc == 3)
	{
		if (is_sorted(stack_a) == -1)
			ft_swap(stack_a, "sa\n");
	}
	else if (argc == 4)
		resolve_three(stack_a);
	else
		resolve_stack(stack_a, stack_b, argc);
}

int	args_len(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
		i++;
	return (i);
}

char	**split_args(int *argc, char **argv, int *tofree)
{
	char	**split_args;

	split_args = ft_split_mult(argv[0], " \t\n");
	*argc = args_len(split_args) + 1;
	*tofree = 1;
	return (split_args);
}

void	ft_free(t_elem *stack_a, t_elem *stack_b, char **split_list, int tofree)
{
	int	i;

	if (tofree)
	{
		i = 0;
		while (split_list[i] != 0)
		{
			free(split_list[i]);
			i++;
		}
		free(split_list[i]);
		free(split_list);
	}
	if (stack_a != NULL)
		free(stack_a);
	if (stack_b != NULL)
		free(stack_b);
}

int	main(int argc, char **argv)
{
	int		error;
	t_elem	*stack_a;
	t_elem	*stack_b;
	char	**split_list;
	int		tofree;

	tofree = 0;
	argv++;
	split_list = argv;
	if (argc == 2)
		split_list = split_args(&argc, argv, &tofree);
	error = ft_handle_errors(argc, split_list);
	if (error == -1 || error == 0)
	{
		ft_free(NULL, NULL, split_list, tofree);
		return (0);
	}
	stack_a = create_tab(argc, split_list, 1);
	stack_b = create_tab(argc, split_list, 0);
	if (is_sorted(stack_a) == -1)
		choose_resolve(stack_a, stack_b, argc);
	ft_free(stack_a, stack_b, split_list, tofree);
	return (0);
}
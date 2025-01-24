/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:37:27 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 14:30:07 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* int main(int argc, char **argv)
{
    t_stack	*a;
    t_stack	*b;
    
    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2 && argv[1][0] == '"')
        argv = ft_split(argv[1], ' ');
    stack_init(&a, argv);
    if (!stack_sorted(a))
    {
        if (stack_size(a) == 2)
            sa(&a);
        else if (stack_size(a) == 3)
            tiny_sort(&a);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
} */

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_pushswap_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, false);
		else if (stack_size(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
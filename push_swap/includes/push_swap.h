/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:41:55 by misoares          #+#    #+#             */
/*   Updated: 2025/01/24 18:49:08 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	long 				value;
	long				current_position;
	long				push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

void			finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void			push_swap(t_stack **a, t_stack **b);
void			free_matrix(char **argv);
void			free_stack(t_stack **stack);
void			error_free(t_stack **a, char **argv, bool flag);
int				error_syntax(char *str_nbr);
int				error_repetition(t_stack *a, int nbr);
void			pa(t_stack **a, t_stack **b, bool flag);
void			pb(t_stack **b, t_stack **a, bool flag);
void			set_current_position(t_stack *stack);
void			set_price(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);
void			init_nodes(t_stack *a, t_stack *b);
void			rra(t_stack **a, bool flag);
void			rrb(t_stack **b, bool flag);
void			rrr(t_stack **a, t_stack **b, bool flag);
void			ra(t_stack **a, bool flag);
void			rb(t_stack **b, bool flag);
void			rr(t_stack **a, t_stack **b, bool flag);
bool			stack_sorted(t_stack *stack);
void			tiny_sort(t_stack **a);
void			handle_five(t_stack **a, t_stack **b);
void			stack_init(t_stack **a, char **argv, bool flag);
void			append_node(t_stack **stack, int nbr);
t_stack			*find_smallest(t_stack *stack);
t_stack			*return_cheapest(t_stack *stack);
void			sa(t_stack **a, bool flag);
void			sb(t_stack **b, bool flag);
void			ss(t_stack **a, t_stack **b, bool flag);
int				stack_size(t_stack *a);
t_stack			*find_last_node(t_stack *lst);
char			**ft_pushswap_split(char *str, char separator);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:41:55 by misoares          #+#    #+#             */
/*   Updated: 2025/04/21 10:05:29 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_elem {
	int		num;
	int		filled;
	int		index;
}	t_elem;

int		ft_handle_errors(int argc, char **argv);
void	push_stack(t_elem *stack_a, t_elem *stack_b, char *str);
void	shift_up(t_elem *stack, char *str);
void	shift_down(t_elem *stack, char *str);
t_elem	*create_tab(int argc, char **argv, int boolean);
void	resolve_stack(t_elem *stack_a, t_elem *stack_b, int stack_size);
void	show_stack(t_elem *stack_a, t_elem *stack_b, int stack_size);
int		get_start_stack(t_elem *stack);
int		get_end_stack(t_elem *stack);
t_elem	get_max_stack(t_elem *stack, int treshold);
t_elem	get_min_stack(t_elem *stack);
int		get_op_for_topplace(t_elem *stack_a, int index, int reel);
int		get_op_for_gplace(t_elem *stack_a, t_elem *stack_b, int index);
void	resolve_three(t_elem *stack);
void	ft_swap(t_elem *stack, char *msg);
t_elem	get_min_above_tresh(t_elem *stack, int treshold);
void	ft_double_shift(t_elem *stack_a, t_elem *stack_b, int down_up);
int		get_coherences(t_elem *stack_a, t_elem *stack_b, int index);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		get_best_op_index(t_elem *stack_a, t_elem *stack_b, int stack_size);
int		is_sorted(t_elem *stack);
int		is_median(t_elem *stack, int num);
char	**ft_split_mult(char *str, char *charset);

#endif
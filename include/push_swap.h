/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:06:09 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/19 16:57:07 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	unsigned int	normalised;
}			t_node;

typedef struct s_bench_metrics
{
	int		operations;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	float	disorder;
	char	*strategy;
	char	*algorithm;
}				t_bench_metrics;

typedef struct s_flags
{
	int	is_simple;
	int	is_medium;
	int	is_complex;
	int	is_adaptive;
	int	is_bench;
}				t_flags;

typedef struct s_stack
{
	t_node			*first;
	t_node			*last;
	unsigned int	size;
	t_bench_metrics	*metrics;
	t_flags			*flags;
}			t_stack;

typedef struct s_qsp
{
	unsigned int	pivot;
	unsigned int	pushed;
	int				rotated;
	int				size;
}				t_qsp;

t_node			*newnode(int value);

t_stack			*init_stack(void);

t_stack			*create_stack_a(int argc, char **argv);

t_bench_metrics	*bench_metrics_init(void);

void			stack_add_front(t_stack *lst, t_node *new);

void			stack_add_back(t_stack *lst, t_node *new);

void			free_lst(t_node **lst);

void			free_stacks(t_stack **a, t_stack **b);

void			free_metrics(t_bench_metrics **metrix);

float			compute_disorder(t_stack *stack);

void			stack_normalisation(t_node *stack);

void			stack_swap(t_stack *lst);

void			stack_push(t_stack *dest, t_stack *src);

void			stack_rotate(t_stack *lst);

void			stack_rrotate(t_stack *lst);

int				get_index(t_node *node, unsigned int val);

void			selection_sort(t_stack *stack_a, t_stack *stack_b);

void			chunk_sort(t_stack *a, t_stack *b);

void			quick_sort(t_stack *a, t_stack *b);

void			adaptive_algorithm(t_stack *a, t_stack *b);

void			push_below_pivot(t_stack *a, t_stack *b, t_qsp *qsp);

void			push_above_pivot(t_stack *a, t_stack *b, t_qsp *qsp);

void			bring_a_to_beginning(t_stack *a, t_stack *b, t_qsp *qsp);

void			bring_b_to_beginning(t_stack *a, t_stack *b, t_qsp *qsp);

void			rules_handling(t_stack *a, t_stack *b, char *rule);

void			handle_small_a(t_stack *a, t_stack *b, int size);

int				is_flag(char *s);

char			**flatten_args(int argc, char **argv, int *total_nums);

void			free_split(char **split);

long			ft_atol(const char *nptr);

int				input_check(int argc, char **argv);

void			find_flags(int argc, char **argv, t_flags *flags);

void			push_swap(t_stack *a, t_stack *b);

void			rotate_n_times(t_stack *a, t_stack *b, int n, char *rule);

void			print_bench(t_bench_metrics *m);

// additional functions (not needed in proj)
void			print_stack(t_stack *stack);

void			print_metrics(t_bench_metrics *metrics);

#endif

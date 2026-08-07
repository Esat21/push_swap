/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:36:02 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/03 19:01:39 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	unsigned int	normalised;
}			t_node;

typedef struct s_stack
{
	t_node			*first;
	t_node			*last;
	unsigned int	size;
}			t_stack;

// checker_rules.c
void	rules_handling_checker(t_stack *a, t_stack *b, char *rule);

// checker_utils.c
char	**read_rules(void);
void	apply_moves(t_stack *a, t_stack *b, char **moves);
long	ft_atol(const char *nptr);

// clear_operations.c
void	free_stacks(t_stack **a, t_stack **b);

// disorder_metric.c
float	compute_disorder(t_stack *stack);

// flattern_args.c
void	free_split(char **split);
char	**flatten_args(int argc, char **argv, int *total_nums);

// input_check.c
int		input_check(int argc, char **argv);

// list_operations.c
t_node	*newnode(int value);
void	stack_add_back(t_stack *lst, t_node *new);
void	stack_add_front(t_stack *lst, t_node *new);

// ps_rules.c
void	stack_swap(t_stack *lst);
void	stack_push(t_stack *dest, t_stack *src);
void	stack_rotate(t_stack *lst);
void	stack_rrotate(t_stack *lst);

// stack_creation.c
t_stack	*init_stack(void);
t_stack	*create_stack_a(int argc, char **argv);

#endif
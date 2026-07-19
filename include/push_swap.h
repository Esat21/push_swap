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
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	unsigned int	normalised;
}			t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	size_t	size;
}			t_stack;

t_node	*newnode(int value);

t_stack	*init_stack(void);

t_stack	*create_stack_a(int argc, char **argv);

void	stack_add_front(t_stack *lst, t_node *new);

void	stack_add_back(t_stack *lst, t_node *new);

void	free_lst(t_node **lst);

void	free_stacks(t_stack **a, t_stack **b);

float	compute_disorder(t_stack *stack);

void	stack_normalisation(t_node *stack);

void	stack_swap(t_stack *lst);

void	stack_push(t_stack *dest, t_stack *src);

void	stack_rotate(t_stack *lst);

void	stack_rrotate(t_stack *lst);

void	selection_sort(t_stack *stack_a, t_stack *stack_b);

// additional functions (not needed in proj)
void	print_stack(t_stack *stack);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:06:09 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/17 12:00:47 by ssokhats         ###   ########.fr       */
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
	unsigned int	normalized;
}			t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	size_t	size;
}			t_stack;

t_node	*newnode(int value);

t_stack	*init_stack(void);

void	stack_add_front(t_stack *lst, t_node *new);

void	stack_add_back(t_stack *lst, t_node *new);

void	free_lst(t_node **lst);

void	free_stacks(t_stack **a, t_stack **b);

float	compute_disorder(t_stack *stack);

#endif
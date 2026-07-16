/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:06:09 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/16 13:11:40 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	int		value;
	t_node	*next;
}			t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	size_t	size;
}			t_stack;


void	stack_add_back(t_stack **lst, t_stack *new);
t_stack	*stacklast(t_stack *lst);
t_stack	*stacknew(int value);
int		ft_atoi_ps(const char *ptr);
int		stack_size(t_stack *lst);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:06:09 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/16 12:51:13 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int		value;
	t_stack	*next;
}			t_stack;

void	stack_add_back(t_stack **lst, t_stack *new);
t_stack	*stacklast(t_stack *lst);
t_stack	*stacknew(int value);
int		ft_atoi_ps(const char *ptr);
int		stack_size(t_stack *lst);

#endif
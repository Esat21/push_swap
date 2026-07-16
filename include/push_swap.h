/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:06:09 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/16 17:40:48 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

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

void	stack_add_back(t_stack *lst, t_node *new);
t_node	*stacknew(int value);
t_stack	*init_stack(void);

#endif
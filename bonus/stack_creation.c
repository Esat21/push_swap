/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:46:13 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/19 16:43:54 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

/**
 * @brief Allocates and initializes a new stack.
 *
 * Dynamically allocates memory for a `t_stack` structure and initializes 
 * its members (`first` and `last` to `NULL`, and `size` to `0`).
 *
 * @return A pointer to the newly allocated and initialized `t_stack` 
 * on success.
 * @retval NULL If memory allocation fails.
 */
t_stack	*init_stack(void)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->first = NULL;
	lst->last = NULL;
	lst->size = 0;
	return (lst);
}

t_stack	*create_stack_a(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	stack_a = init_stack();
	i = -1;
	while (++i < argc)
		stack_add_back(stack_a, newnode(ft_atoi(argv[i])));
	return (stack_a);
}

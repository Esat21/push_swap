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

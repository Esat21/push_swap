/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:36:05 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/19 16:45:19 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_index(t_node *node, int val)
{
	int	i;

	i = 0;
	if (!node)
		return (-1);
	while (node->value != val)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	n;

	i = 0;
	while (stack_a->first)
	{
		if (stack_a->first->normalised == i)
		{
			stack_push(stack_b, stack_a);
			i++;
			continue ;
		}
		if ((stack_a->size / 2 - get_index(stack_a->first, i)) < 0)
			stack_rrotate(stack_a);
		else
			stack_rotate(stack_a);
	}
	while (stack_b->first)
		stack_push(stack_a, stack_b);
}

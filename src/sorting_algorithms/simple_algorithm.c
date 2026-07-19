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
	while (node && node->normalised != val)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b, t_bench_metrics *m)
{
	int	i;

	i = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->first && stack_a->first->normalised == i)
		{
			rules_handling(stack_a, stack_b, "pb", m);
			// stack_push(stack_b, stack_a);
			i++;
			continue ;
		}
		if ((stack_a->size / 2 - get_index(stack_a->first, i)) < 0)
			rules_handling(stack_a, stack_b, "rra", m);
			// stack_rrotate(stack_a);
		else
			rules_handling(stack_a, stack_b, "ra", m);
			// stack_rotate(stack_a);
	}
	while (stack_b->size > 0)
		rules_handling(stack_a, stack_b, "pa", m);
		// stack_push(stack_a, stack_b);
}

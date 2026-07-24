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

unsigned int	get_index(t_node *node, unsigned int val)
{
	unsigned int	i;

	i = 0;
	while (node && node->normalised != val)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b, t_bench_metrics *m)
{
	unsigned int	i;

	i = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->first && stack_a->first->normalised == i)
		{
			rules_handling(stack_a, stack_b, "pb", m);
			i++;
			continue ;
		}
		if (((int)stack_a->size / 2 - (int)get_index(stack_a->first, i)) < 0)
			rules_handling(stack_a, stack_b, "rra", m);
		else
			rules_handling(stack_a, stack_b, "ra", m);
	}
	while (stack_b->size > 0)
		rules_handling(stack_a, stack_b, "pa", m);
}

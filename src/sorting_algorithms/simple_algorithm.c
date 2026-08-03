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

#include "push_swap.h"

int	get_index(t_node *node, unsigned int val)
{
	int	i;

	i = 0;
	while (node && node->normalised != val)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;
	int				target;

	i = 0;
	stack_a->metrics->algorithm = ft_strdup("O(n²)");
	while (stack_a->size > 2)
	{
		if (stack_a->first && stack_a->first->normalised == i)
		{
			rules_handling(stack_a, stack_b, "pb");
			i++;
			continue ;
		}
		target = get_index(stack_a->first, i);
		if (((int)stack_a->size / 2 - target) < 0)
			rotate_n_times(stack_a, stack_b, stack_a->size - target, "rra");
		else
			rotate_n_times(stack_a, stack_b, target, "ra");
	}
	handle_small_a(stack_a, stack_b, stack_a->size);
	while (stack_b->size > 0)
		rules_handling(stack_a, stack_b, "pa");
}

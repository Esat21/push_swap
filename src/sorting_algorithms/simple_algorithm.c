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

int	get_index(t_node *node, unsigned int val)
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

unsigned int	target_pos_calc(t_node *a_curr, t_stack *b)
{
	t_node	*next;
	t_node	*b_current;
	t_node	*minimum;
	t_node	*maximum;

	b_current = b->first;
	minimum = b_current;
	maximum = b_current;
	while(b_current)
	{
		if (b_current->next)
			next = b_current->next;
		else
			next = b->first;
		if (b_current->normalised < minimum->normalised)
			minimum = b_current;
		if (b_current->normalised > maximum->normalised)
			maximum = b_current;
		if (a_curr->normalised < b_current->normalised && a_curr->normalised > next->normalised)
			return (next->normalised);
		b_current = b_current->next;
	}
	if (a_curr->normalised > maximum->normalised)
		return (maximum->normalised);
	return (minimum->normalised);
}

void	insertion_sort(t_stack *a, t_stack *b, t_bench_metrics *m)
{
	unsigned int	target_pos;

	if (a->size > 1)
		rules_handling(a, b, "pb", m);
	while (a->first && a->size > 0)
	{
		target_pos = target_pos_calc(a->first, b);
		printf("Target: %d\n", target_pos);
		if (b->first && b->first->normalised == target_pos)
		{
			rules_handling(a, b, "pb", m);
			continue ;
		}
		if (((b->size / 2) - get_index(b->first, target_pos)) > 0)
			rules_handling(a, b, "rrb", m);
		else
			rules_handling(a, b, "rb", m);
	}
	while (b->first->normalised != b->size - 1)
	{
		if ((b->size / 2 - get_index(b->first, b->size - 1)) > 0)
			rules_handling(a, b, "rrb", m);
		else
			rules_handling(a, b, "rb", m);
	}
	while (b->size > 0)
		rules_handling(a, b, "pa", m);
	rules_handling(a, b, "sa", m);
}

/* 4 3 2 8 6

7 */
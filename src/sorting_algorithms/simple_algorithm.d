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

int		target_pos_calc(t_node *b_curr, t_stack *a)
{
	t_node	*next;
	t_node	*a_current;

	a_current = a->first;
	while(a_current)
	{
		if (!a_current->next && a->size > 1)
			next = a->first;
		else
			next = a_current->next;
		if ((b_curr->normalised < a_current->normalised) && (b_curr->normalised > next->normalised))
			return (next->normalised); // returning the node we put the number after. I.e. for a:2 and b:4 3 1, we return 1. Rethink?
		else
			a_current = a_current->next;
	}
	return (-1);
}

void	r_insertion_sort(t_stack *a, t_stack *b, t_bench_metrics *m)
{
	unsigned int	i;

	i = 0;
	while (a->first->next && i < a->size - 1)
	{
		if (a->first->normalised < a->last->normalised)
		{
			rules_handling(a, b, "pb", m);
			continue ;
		}
		rules_handling(a, b, "ra", m);
		i++;
	}
}

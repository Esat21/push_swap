/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 00:00:00 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/23 00:00:00 by esyaman          ###   ########.fr       */
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

/*
** b is kept as a "rotated descending sequence": walking it from wherever
** b->first currently points, values decrease and wrap upward exactly once.
** A value outside [b_min, b_max] always belongs right next to the current
** max (on either side of that single wrap point), so both out-of-range
** cases share the same target: b_max.
*/
unsigned int	find_target(t_sort_ctx *ctx, unsigned int val)
{
	t_node	*curr;
	t_node	*next;

	if (val > ctx->b_max || val < ctx->b_min)
		return (ctx->b_max);
	curr = ctx->b->first;
	while (curr)
	{
		if (curr->next)
			next = curr->next;
		else
			next = ctx->b->first;
		if (curr->normalised > val && next->normalised < val)
			return (next->normalised);
		curr = curr->next;
	}
	return (ctx->b_max);
}

void	rotate_a_n(t_stack *a, t_stack *b, int forward, unsigned int n,
	t_bench_metrics *m)
{
	while (n-- > 0)
	{
		if (forward)
			rules_handling(a, b, "ra", m);
		else
			rules_handling(a, b, "rra", m);
	}
}

void	rotate_b_n(t_stack *a, t_stack *b, int forward, unsigned int n,
	t_bench_metrics *m)
{
	while (n-- > 0)
	{
		if (forward)
			rules_handling(a, b, "rb", m);
		else
			rules_handling(a, b, "rrb", m);
	}
}

void	rotate_both_n(t_stack *a, t_stack *b, int forward, unsigned int n,
	t_bench_metrics *m)
{
	while (n-- > 0)
	{
		if (forward)
			rules_handling(a, b, "rr", m);
		else
			rules_handling(a, b, "rrr", m);
	}
}

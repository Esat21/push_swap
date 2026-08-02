/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algoritm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:15:13 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/24 15:15:49 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_b(t_stack *a, t_stack *b, int min, int max);

void	handle_small_a(t_stack *a, t_stack *b, int size)
{
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (a->first->normalised > a->first->next->normalised)
			rules_handling(a, b, "sa");
		return ;
	}
}

void	handle_small_b(t_stack *a, t_stack *b, int size)
{
	if (size == 1)
	{
		rules_handling(a, b, "pa");
		return ;
	}
	if (size == 2)
	{
		if (b->first->normalised < b->first->next->normalised)
			rules_handling(a, b, "sb");
		rules_handling(a, b, "pa");
		rules_handling(a, b, "pa");
		return ;
	}
}

void	quick_sort_a(t_stack *a, t_stack *b, int min, int max)
{
	t_qsp	qsp;

	qsp.pushed = min;
	qsp.size = max - min + 1;
	if (qsp.size <= 2)
	{
		handle_small_a(a, b, qsp.size);
		return ;
	}
	qsp.pivot = min + (qsp.size / 2);
	qsp.rotated = 0;
	push_below_pivot(a, b, &qsp);
	bring_a_to_beginning(a, b, &qsp);
	quick_sort_a(a, b, qsp.pivot, max);
	quick_sort_b(a, b, min, qsp.pivot - 1);
}

void	quick_sort_b(t_stack *a, t_stack *b, int min, int max)
{
	t_qsp	qsp;

	qsp.pushed = min;
	qsp.size = max - min + 1;
	if (qsp.size <= 2)
	{
		handle_small_b(a, b, qsp.size);
		return ;
	}
	qsp.pivot = min + (qsp.size / 2);
	qsp.rotated = 0;
	push_above_pivot(a, b, &qsp);
	bring_b_to_beginning(a, b, &qsp);
	quick_sort_a(a, b, qsp.pivot, max);
	quick_sort_b(a, b, min, qsp.pivot - 1);
}

void	quick_sort(t_stack *a, t_stack *b)
{
	a->metrics->algorithm = ft_strdup("O(n log n)");
	quick_sort_a(a, b, 0, a->size - 1);
}

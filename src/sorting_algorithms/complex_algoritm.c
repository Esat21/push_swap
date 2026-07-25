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

#include "../../include/push_swap.h"

void	quick_sort_b(t_stack *a, t_stack *b, int min, int max, t_bench_metrics *m);

void handle_small_a(t_stack *a, t_stack *b, int size, t_bench_metrics *m)
{
    if (size <= 1)
        return ;
    if (size == 2)
    {
        if (a->first->normalised > a->first->next->normalised)
            rules_handling(a, b, "sa", m);
        return ;
    }
    if (size == 3)
    {
        int first = a->first->value;
        int second = a->first->next->value;
        int third = a->first->next->next->value;

        // Pattern: [2, 1, 3] -> swap to get [1, 2, 3]
        if (first > second && second < third && first < third)
            rules_handling(a, b, "sa", m);
        // Pattern: [3, 1, 2] -> ra, sa, rra
        else if (first > second && second < third && first > third)
        {
            rules_handling(a, b, "ra", m);
            rules_handling(a, b, "sa", m);
            rules_handling(a, b, "rra", m);
        }
        // Pattern: [1, 3, 2] -> ra, sa, rra, sa
        else if (first < second && second > third && first < third)
        {
            rules_handling(a, b, "ra", m);
            rules_handling(a, b, "sa", m);
            rules_handling(a, b, "rra", m);
            // rules_handling(a, b, "sa", m); ???
        }
        // Pattern: [2, 3, 1] -> sa, ra, sa, rra
        else if (first < second && second > third && first > third)
        {
            rules_handling(a, b, "sa", m);
            rules_handling(a, b, "ra", m);
            rules_handling(a, b, "sa", m);
            rules_handling(a, b, "rra", m);
        }
        // Pattern: [3, 2, 1] -> sa, ra, sa, rra, sa
        else if (first > second && second > third)
        {
            rules_handling(a, b, "sa", m);
            rules_handling(a, b, "ra", m);
            rules_handling(a, b, "sa", m);
            rules_handling(a, b, "rra", m);
            rules_handling(a, b, "sa", m);
        }
    }
}

void handle_small_b(t_stack *a, t_stack *b, int size, t_bench_metrics *m)
{
    if (size == 1)
    {
        rules_handling(a, b, "pa", m);
        return ;
    }
    if (size == 2)
    {
        // Stack B top should be larger than second element before pushing
        if (b->first->value < b->first->next->value)
            rules_handling(a, b, "sb", m);
        rules_handling(a, b, "pa", m);
        rules_handling(a, b, "pa", m);
        return ;
    }
    if (size == 3)
    {
        // Push all 3 elements to Stack A first
        for (int i = 0; i < 3; i++)
	        rules_handling(a, b, "pa", m);
        // Now sort the 3 elements on top of Stack A using handle_small_a
        handle_small_a(a, b, 3, m);
    }
}

void	quick_sort_a(t_stack *a, t_stack *b, int min, int max, t_bench_metrics *m)
{
	unsigned int	pivot;
	int	rotated;
	int	size;
	int	i;

	size = max - min + 1;
	if (size <= 3)
	{
		handle_small_a(a, b, size, m);
		return ;
	}
	pivot = min + (size / 2);
	rotated = 0;
	i = 0;
	while (i++ < size && a->first)
	{
		if (a->first->normalised < pivot)
			rules_handling(a, b, "pb", m);
		else
		{
			rules_handling(a, b, "ra", m);
			rotated++;
		}
	}
	i = 0;
	while (i++ < rotated)
		rules_handling(a, b, "rra", m);
	quick_sort_a(a, b, pivot, max, m);
	quick_sort_b(a, b, min, pivot - 1, m);
}

void	quick_sort_b(t_stack *a, t_stack *b, int min, int max, t_bench_metrics *m)
{
	unsigned int	pivot;
	int	rotated;
	int	size;
	int	i;

	size = max - min + 1;
	if (size <= 3)
	{
		handle_small_b(a, b, size, m);
		return ;
	}
	pivot = min + (size / 2);
	rotated = 0;
	i = 0;
	while (i++ < size && b->first)
	{
		if (b->first->normalised >= pivot)
			rules_handling(a, b, "pa", m);
		else
		{
			rules_handling(a, b, "rb", m);
			rotated++;
		}
	}
	i = 0;
	while (i++ < rotated)
		rules_handling(a, b, "rrb", m);
	quick_sort_a(a, b, pivot, max, m);
	quick_sort_b(a, b, min, pivot - 1, m);
}

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

void handle_small_b(t_stack *a, t_stack *b, int size)
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
	unsigned int	pivot;
	int	rotated;
	int	size;
	int	i;
	unsigned int	pushed;

	pushed = min;
	size = max - min + 1;
	if (size <= 2)
	{
		handle_small_a(a, b, size);
		return ;
	}
	pivot = min + (size / 2);
	rotated = 0;
	i = 0;
	while (i++ < size && a->first && pushed < pivot)
	{
		if (a->first->normalised < pivot)
		{
			rules_handling(a, b, "pb");
			pushed++;
		}
		else
		{
			rules_handling(a, b, "ra");
			rotated++;
		}
	}
	i = 0;
	if ((int)a->size / 2 - rotated > 0)
	{
		while (i++ < rotated)
			rules_handling(a, b, "rra");
	}
	else 
	{
		while ((unsigned int)i++ < (a->size - rotated + 1))
			rules_handling(a, b, "ra");
	}
	quick_sort_a(a, b, pivot, max);
	quick_sort_b(a, b, min, pivot - 1);
}

void	quick_sort_b(t_stack *a, t_stack *b, int min, int max)
{
	unsigned int	pivot;
	int	rotated;
	int	size;
	int	i;
	unsigned int	pushed;

	pushed = min;
	size = max - min + 1;
	if (size <= 2)
	{
		handle_small_b(a, b, size);
		return ;
	}
	pivot = min + (size / 2);
	rotated = 0;
	i = 0;
	while (i++ < size && b->first && pushed <= pivot)
	{
		if (b->first->normalised >= pivot)
		{
			rules_handling(a, b, "pa");
			pushed++;
		}
		else
		{
			rules_handling(a, b, "rb");
			rotated++;
		}
	}
	i = 0;
	if ((int)b->size / 2 - rotated > 0)
	{
		while (i++ < rotated)
			rules_handling(a, b, "rrb");
	}
	else 
	{
		while ((unsigned int)i++ < (b->size - rotated + 1))
			rules_handling(a, b, "rb");
	}
	quick_sort_a(a, b, pivot, max);
	quick_sort_b(a, b, min, pivot - 1);
}

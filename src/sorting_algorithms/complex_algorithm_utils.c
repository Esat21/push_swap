/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:42:49 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/27 20:42:49 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_below_pivot(t_stack *a, t_stack *b, t_qsp *qsp)
{
	int	i;

	i = 0;
	while (i++ < qsp->size && a->first && qsp->pushed < qsp->pivot)
	{
		if (a->first->normalised < qsp->pivot)
		{
			rules_handling(a, b, "pb");
			qsp->pushed++;
		}
		else
		{
			rules_handling(a, b, "ra");
			qsp->rotated++;
		}
	}
}

void	push_above_pivot(t_stack *a, t_stack *b, t_qsp *qsp)
{
	int	i;

	i = 0;
	while (i++ < qsp->size && b->first && qsp->pushed <= qsp->pivot)
	{
		if (b->first->normalised >= qsp->pivot)
		{
			rules_handling(a, b, "pa");
			qsp->pushed++;
		}
		else
		{
			rules_handling(a, b, "rb");
			qsp->rotated++;
		}
	}
}

void	bring_a_to_beginning(t_stack *a, t_stack *b, t_qsp *qsp)
{
	int	i;

	i = 0;
	if ((int)a->size / 2 - qsp->rotated >= 0)
	{
		while (i++ < qsp->rotated)
			rules_handling(a, b, "rra");
	}
	else 
	{
		while ((unsigned int)i++ < (a->size - qsp->rotated))
			rules_handling(a, b, "ra");
	}
}

void	bring_b_to_beginning(t_stack *a, t_stack *b, t_qsp *qsp)
{
	int	i;

	i = 0;
	if ((int)b->size / 2 - qsp->rotated >= 0)
	{
		while (i++ < qsp->rotated)
			rules_handling(a, b, "rrb");
	}
	else 
	{
		while ((unsigned int)i++ < (b->size - qsp->rotated))
			rules_handling(a, b, "rb");
	}
}

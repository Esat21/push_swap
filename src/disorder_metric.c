/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:47:30 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/16 14:55:59 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Computes the disorder ratio of the stack.
 *
 * This function calculates the ratio of "disordered" pairs (inversions) 
 * to the total number of unique pairs in the stack. A sorted stack will 
 * return 0.0, while a completely reversed stack will return 1.0.
 *
 * @param blabla A pointer to the stack structure to be analyzed.
 * @return float The disorder ratio ranging from 0.0 (perfectly sorted) 
 * to 1.0 (completely reversed). Returns 0.0 if the stack is 
 * empty or has fewer than two elements.
 */
float	compute_disorder(t_stack *stack)
{
	float	mistakes;
	float	total_pairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	total_pairs = 0;
	i = stack->first;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}

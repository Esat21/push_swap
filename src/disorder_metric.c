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

#include "push_swap.h"

float	compute_disorder(t_stack *stack)
{
	float	mistakes;
	float	total_pairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	total_pairs = 0;
	i = stack->first;
	while (i && i->next)
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
	if (!total_pairs)
		return (0);
	return (mistakes / total_pairs);
}

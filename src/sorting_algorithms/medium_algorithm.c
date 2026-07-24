/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:19:48 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/20 20:19:48 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	get_index_in_range(t_node *node, unsigned int range)
{
	int	i;
	int	j;
	int	last_occurrence;

	i = 0;
	if (!node)
		return (-1);
	while (node && node->normalised > range - 1)
	{
		node = node->next;
		i++;
	}
	j = i;
	while (node)
	{
		if (node->normalised < range)
			last_occurrence = j;
		j++;
		node = node->next;
	}
	if (j - last_occurrence < i)
		return (last_occurrence);
	return (i);
}

void	chunk_sort(t_stack *a, t_stack *b, t_bench_metrics *metrix)
{
	unsigned int	i;
	int				j;
	unsigned int	chunk_size;

	i = 0;
	j = 1;
	chunk_size = ft_sqrt(a->size) * 2;
	while (a->size > 0)
	{
		if (a->first->normalised < (chunk_size * j))
		{
			rules_handling(a, b, "pb", metrix);
			i++;
			if (b->first->normalised < ((chunk_size * j) - (chunk_size / 2)))
				rules_handling(a, b, "rb", metrix);
			continue ;
		}
		if (((int)a->size / 2 - get_index_in_range(a->first, chunk_size * j)) < 0)
			rules_handling(a, b, "rra", metrix);
		else
			rules_handling(a, b, "ra", metrix);
		if (i == chunk_size * j)
			j++;
	}
	while (b->size > 0)
	{
		if (b->first && b->first->normalised == b->size - 1)
		{
			rules_handling(a, b, "pa", metrix);
			continue ;
		}
		if (((int)b->size / 2 - (int)get_index(b->first, b->size - 1)) < 0)
			rules_handling(a, b, "rrb", metrix);
		else
			rules_handling(a, b, "rb", metrix);
	}
}

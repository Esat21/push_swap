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

#include "push_swap.h"

static int	ft_sqrt(int n)
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
	last_occurrence = 0;
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

void	sort_chunks(t_stack *a, t_stack *b, unsigned int chunk_size)
{
	unsigned int	i;
	int				j;
	int				closest;

	i = 0;
	j = 1;
	while (a->size > 0)
	{
		if (a->first->normalised < (chunk_size * j))
		{
			rules_handling(a, b, "pb");
			i++;
			if (b->first->normalised < ((chunk_size * j) - (chunk_size / 2)))
				rules_handling(a, b, "rb");
			continue ;
		}
		closest = get_index_in_range(a->first, chunk_size * j);
		if (((int)a->size / 2 - closest) < 0)
			rules_handling(a, b, "rra");
		else
			rules_handling(a, b, "ra");
		if (i == chunk_size * j)
			j++;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	unsigned int	chunk_size;
	int				target;

	a->metrics->algorithm = ft_strdup("O(n√n)");
	chunk_size = 5;
	if (a->size > 5)
		chunk_size = ft_sqrt(a->size) * 2;
	sort_chunks(a, b, chunk_size);
	while (b->size > 0)
	{
		if (b->first && b->first->normalised == b->size - 1)
		{
			rules_handling(a, b, "pa");
			continue ;
		}
		target = get_index(b->first, b->size - 1);
		if (((int)b->size / 2 - target) < 0)
			rotate_n_times(a, b, b->size - target, "rrb");
		else
			rotate_n_times(a, b, target, "rb");
	}
}

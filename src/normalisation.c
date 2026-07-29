/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:11:32 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/19 15:11:32 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Assigns a relative rank to each node's value in the stack.
 *
 * This function normalizes the stack by counting how many other nodes have a
 * strictly greater value than the current node. It updates the `normalised`
 * field of each node, effectively giving it a rank (where higher values get
 * smaller ranks, and the absolute maximum value gets a rank of 0).
 *
 * @param stack A pointer to the first node of the stack.
 */
void	stack_normalisation(t_node *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack;
	while (i)
	{
		j = stack;
		while (j)
		{
			if (i->value > j->value)
				i->normalised++;
			j = j->next;
		}
		i = i->next;
	}
}

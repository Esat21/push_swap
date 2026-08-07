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

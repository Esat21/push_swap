/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:42:22 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/19 17:07:33 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_lst(t_node **lst)
{
	t_node	*curr;
	t_node	*next;

	if (!lst || !*lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

void	free_stacks(t_stack **a, t_stack **b)
{
	if (a && *a)
	{
		free_lst(&((*a)->first));
		(*a)->last = NULL;
		free(*a);
		*a = NULL;
	}
	if (b && *b)
	{
		free_lst(&((*b)->first));
		(*b)->last = NULL;
		free(*b);
		*b = NULL;
	}
}

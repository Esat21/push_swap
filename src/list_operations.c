/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:45:45 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/19 16:43:05 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*newnode(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->normalised = 0;
	return (new_node);
}

void	stack_add_back(t_stack *lst, t_node *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (lst->first == NULL)
	{
		lst->first = new;
		lst->last = new;
		lst->size++;
		return ;
	}
	lst->last->next = new;
	lst->last = new;
	lst->size++;
}

void	stack_add_front(t_stack *lst, t_node *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (lst->first == NULL)
	{
		new->next = NULL;
		lst->first = new;
		lst->last = new;
		lst->size++;
		return ;
	}
	new->next = lst->first;
	lst->first = new;
	lst->size++;
}

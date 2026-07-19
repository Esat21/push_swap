/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:40:28 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/19 16:07:38 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_swap(t_stack *lst)
{
	t_node	*buff;

	buff = lst->first->next;
	lst->first->next = lst->first->next->next;
	buff->next = lst->first;
	lst->first = buff;
}

void	stack_push(t_stack *dest, t_stack *src)
{
	t_node	*buff;

	buff = src->first->next;
	stack_add_front(dest, src->first);
	src->first = buff;
	src->size--;
	if (src->size == 1)
		src->last = src->first;
}

void	stack_rotate(t_stack *lst)
{
	lst->last->next = lst->first;
	lst->last = lst->first;
	lst->first = lst->first->next;
	lst->last->next = NULL;
}

void	stack_rrotate(t_stack *lst)
{
	t_node	*second_last;

	second_last = lst->first;
	while (second_last->next->next)
		second_last = second_last->next;
	lst->last->next = lst->first;
	lst->first = lst->last;
	lst->last = second_last;
	second_last->next = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:40:28 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/16 17:58:24 by esyaman          ###   ########.fr       */
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
	dest->first->next =
	dest->first = src->first;
}
/*
first->next = second
second->next = third
third->next = fourth

buff = second





*/
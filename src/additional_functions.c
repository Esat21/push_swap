/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:57:40 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/19 17:01:46 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node	*curr;

	curr = stack->first;
	while(curr)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

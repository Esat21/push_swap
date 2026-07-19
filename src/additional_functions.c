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

void	print_metrics(t_bench_metrics *metrics)
{
	printf("operations: %d\ndisorder: %.2f\nsa: %d\nsb: %d\nss: %d\npa: %d\npb: %d\nra: %d\nrb: %d\nrr: %d\nrra: %d\nrrb: %d\nrrr: %d\n", metrics->operations, metrics->disorder, metrics->sa, metrics->sb, metrics->ss, metrics->pa, metrics->pb, metrics->ra, metrics->rb, metrics->rr, metrics->rra, metrics->rrb, metrics->rrr);
}

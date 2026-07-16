/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:47:30 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/16 12:52:49 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	compute_disorder(t_stack *stack_a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	stack_size;

	stack_size = 
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while ()
}


/*
function compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
for j from i+1 to size(a)-1:
total_pairs += 1
if a[i] > a[j]:
mistakes += 1
return mistakes / total_pairs
*/
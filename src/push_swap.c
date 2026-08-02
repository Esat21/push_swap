/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:22:43 by ssokhats          #+#    #+#             */
/*   Updated: 2026/08/02 17:43:05 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	stack_normalisation(a->first);
	a->metrics->disorder = compute_disorder(a);
	if (a->flags->is_simple)
	{
		a->metrics->strategy = ft_strdup("Simple");
		selection_sort(a, b);
	}
	else if (a->flags->is_medium)
	{
		a->metrics->strategy = ft_strdup("Medium");
		chunk_sort(a, b);
	}
	else if (a->flags->is_complex)
	{
		a->metrics->strategy = ft_strdup("Complex");
		quick_sort(a, b);
	}
	else if (a->flags->is_adaptive)
	{
		a->metrics->strategy = ft_strdup("Adaptive");
		adaptive_algorithm(a, b);
	}
}

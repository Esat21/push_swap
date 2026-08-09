/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:35:48 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/09 13:35:48 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_algorithm(t_stack *a, t_stack *b)
{
	if (a->metrics->disorder < 0.2)
		selection_sort(a, b);
	else if (a->metrics->disorder < 0.500)
		chunk_sort(a, b);
	else
		quick_sort(a, b);
}

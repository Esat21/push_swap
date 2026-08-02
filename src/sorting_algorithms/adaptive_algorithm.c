/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:15:01 by ssokhats          #+#    #+#             */
/*   Updated: 2026/08/02 17:42:40 by ssokhats         ###   ########.fr       */
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

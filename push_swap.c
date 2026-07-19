/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:32:05 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/19 17:08:19 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;

	stack_a = create_stack_a(argc, argv);
	stack_b = init_stack();
	stack_normalisation(stack_a->first);
	print_stack(stack_a);
	selection_sort(stack_a, stack_b);
	print_stack(stack_a);
	free_stacks(&stack_a, &stack_b);
	return (0);
}

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

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**flatened_argc;
	int		total_args;

	flatened_argc = flatten_args(argc, argv, &total_args);
	if (input_check(total_args, flatened_argc))
	{
		stack_a = create_stack_a(total_args, flatened_argc);
		stack_b = init_stack();
		find_flags(total_args, flatened_argc, stack_a->flags);
		print_stack(stack_a);
		push_swap(stack_a, stack_b);
		print_stack(stack_a);
		print_metrics(stack_a->metrics);
		free_stacks(&stack_a, &stack_b);
	}
	free_split(flatened_argc);
	return (0);
}

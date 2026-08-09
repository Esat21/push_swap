/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:32:05 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/08 23:40:03 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**flatened_argv;
	int		total_args;

	flatened_argv = flatten_args(argc, argv, &total_args);
	if (input_check(total_args, flatened_argv))
	{
		stack_a = create_stack_a(total_args, flatened_argv);
		stack_b = init_stack();
		stack_a->metrics->disorder = compute_disorder(stack_a);
		find_flags(total_args, flatened_argv, stack_a->flags);
		if (is_unique_nums(stack_a))
		{
			if (stack_a->metrics->disorder != 0)
				push_swap(stack_a, stack_b);
			if (stack_a->flags->is_bench)
				print_bench(stack_a->metrics);
		}
		else
			ft_putendl_fd("Error", 2);
		free_stacks(&stack_a, &stack_b);
	}
	free_split(flatened_argv);
	return (0);
}

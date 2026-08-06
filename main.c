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
#include "bonus/bonus.h"

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
		if (!find_flags(total_args, flatened_argv, stack_a->flags))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		push_swap(stack_a, stack_b);
		if (stack_a->flags->is_bench)
			print_bench(stack_a->metrics);
		free_stacks(&stack_a, &stack_b);
	}
	free_split(flatened_argv);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:49:38 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/04 11:24:07 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	char	**flatened_argc;
	int		total_args;
	char	**moves;
	t_stack	*stack_a;
	t_stack	*stack_b;

	flatened_argc = flatten_args(argc, argv, &total_args);
	if (input_check(total_args, flatened_argc))
	{
		stack_a = create_stack_a(total_args, flatened_argc);
		stack_b = init_stack();
		moves = read_rules();
		apply_moves(stack_a, stack_b, moves);
		stack_a->metrics->disorder = compute_disorder(stack_a);
		if (stack_a->metrics->disorder == 0 && !stack_b->size)
			ft_printf_fd(1, "OK\n");
		else
			ft_printf_fd(1, "KO\n");
		free_split(moves);
		free_stacks(&stack_a, &stack_b);
	}
	free_split(flatened_argc);
	return (0);
}

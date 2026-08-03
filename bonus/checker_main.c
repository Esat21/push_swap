/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:49:38 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/03 19:42:54 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	checker_bonus(int argv, char **argc)
{
	char	**flatened_argc;
	int		total_args;
	char	**moves;
	t_stack	*stack_a;
	t_stack	*stack_b;

	flatened_argc = flatten_args(argc, argv, &total_args, ' ');
	
	if (input_check(total_args, flatened_argc))
	{
		stack_a = create_stack_a(total_args, flatened_argc);
		stack_b = init_stack();
		moves = read_rules();
	}
}
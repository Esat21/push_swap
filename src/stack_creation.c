/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:46:13 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/17 10:41:14 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_stack_a(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	stack_a = init_stack();
	i = 0;
	while (++i < argc)
		stack_add_back(stack_a, newnode(ft_atoi(argv[i])));
	return (stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:46:13 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/13 21:12:13 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_stack_a(int argc, char **argv)
{
	int	i;
	t_stack *stack_a;

	i = 0;
	stack_a = stacknew(argv[0]); //todo atoi(argv[0]) when libft will be added
	while (++i < argc)
		stack_add_back(&stack_a, stacknew(argv[0])); //same shit
	return (stack_a);
}

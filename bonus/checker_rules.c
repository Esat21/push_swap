/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 20:38:36 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/07 12:22:32 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	handler_1(t_stack *a, t_stack *b, char *rule)
{
	if (ft_strncmp("sa", rule, 3) == 0)
	{
		stack_swap(a);
		return (1);
	}
	else if (ft_strncmp("sb", rule, 3) == 0)
	{
		stack_swap(b);
		return (1);
	}
	else if (ft_strncmp("pa", rule, 3) == 0)
	{
		stack_push(a, b);
		return (1);
	}
	else if (ft_strncmp("pb", rule, 3) == 0)
	{
		stack_push(b, a);
		return (1);
	}
	else 
		return (0);
}

static int	handler_2(t_stack *a, t_stack *b, char *rule)
{
	if (ft_strncmp("ss", rule, 3) == 0)
	{
		stack_swap(a);
		stack_swap(b);
		return (1);
	}
	else if (ft_strncmp("ra", rule, 3) == 0)
	{
		stack_rotate(a);
		return (1);
	}
	else if (ft_strncmp("rb", rule, 3) == 0)
	{
		stack_rotate(b);
		return (1);
	}
	else if (ft_strncmp("rr", rule, 3) == 0)
	{
		stack_rotate(a);
		stack_rotate(b);
		return (1);
	}
	else
		return (0);

}

static int	handler_3(t_stack *a, t_stack *b, char *rule)
{
	if (ft_strncmp("rrb", rule, 4) == 0)
	{
		stack_rrotate(b);
		return (1);
	}
	else if (ft_strncmp("rrr", rule, 4) == 0)
	{
		stack_rrotate(a);
		stack_rrotate(b);
		return (1);
	}
	else if (ft_strncmp("rra", rule, 4) == 0)
	{
		stack_rrotate(a);
		return (1);
	}
	else
		return (0);
}

int	rules_handling_checker(t_stack *a, t_stack *b, char *rule)
{
	if (handler_1(a, b, rule) + handler_2(a, b, rule)
		+ handler_3(a, b, rule) < 1)
			return (0);
	else
		return (1);
}

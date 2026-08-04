/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 20:38:36 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/04 20:41:35 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 22:27:33 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/19 22:27:33 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	handler_1(t_stack *a, t_stack *b, char *rule)
{
	if (ft_strncmp("sa", rule, 3) == 0)
	{
		stack_swap(a);
		a->metrics->sa++;
	}
	else if (ft_strncmp("sb", rule, 3) == 0)
	{
		stack_swap(b);
		a->metrics->sb++;
	}
	else if (ft_strncmp("pa", rule, 3) == 0)
	{
		stack_push(a, b);
		a->metrics->pa++;
	}
	else if (ft_strncmp("pb", rule, 3) == 0)
	{
		stack_push(b, a);
		a->metrics->pb++;
	}
	else if (ft_strncmp("ra", rule, 3) == 0)
	{
		stack_rotate(a);
		a->metrics->ra++;
	}
}

static void	handler_2(t_stack *a, t_stack *b, char *rule)
{
	if (ft_strncmp("ss", rule, 3) == 0)
	{
		stack_swap(a);
		stack_swap(b);
		a->metrics->ss++;
	}
	else if (ft_strncmp("rb", rule, 3) == 0)
	{
		stack_rotate(b);
		a->metrics->rb++;
	}
	else if (ft_strncmp("rr", rule, 3) == 0)
	{
		stack_rotate(a);
		stack_rotate(b);
		a->metrics->rr++;
	}
	else if (ft_strncmp("rra", rule, 4) == 0)
	{
		stack_rrotate(a);
		a->metrics->rra++;
	}
}

static void	handler_3(t_stack *a, t_stack *b, char *rule)
{
	if (ft_strncmp("rrb", rule, 4) == 0)
	{
		stack_rrotate(b);
		a->metrics->rrb++;
	}
	else if (ft_strncmp("rrr", rule, 4) == 0)
	{
		stack_rrotate(a);
		stack_rrotate(b);
		a->metrics->rrr++;
	}
}

void	rules_handling_checker(t_stack *a, t_stack *b, char *rule)
{
	handler_1(a, b, rule);
	handler_2(a, b, rule);
	handler_3(a, b, rule);
	a->metrics->operations++;
}

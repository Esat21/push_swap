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

#include "../include/push_swap.h"

void	handler_1(
	t_stack *a,
	t_stack *b,
	char *rule,
	t_bench_metrics *metrics
)
{
	if (ft_strncmp("sa", rule, 3) == 0)
	{
		stack_swap(a);
		metrics->sa++;
	}
	else if (ft_strncmp("sb", rule, 3) == 0)
	{
		stack_swap(b);
		metrics->sb++;
	}
	else if (ft_strncmp("pa", rule, 3) == 0)
	{
		stack_push(a, b);
		metrics->pa++;
	}
	else if (ft_strncmp("pb", rule, 3) == 0)
	{
		stack_push(b, a);
		metrics->pb++;
	}
	else if (ft_strncmp("ra", rule, 3) == 0)
	{
		stack_rotate(a);
		metrics->ra++;
	}
}

void	handler_2(
	t_stack *a,
	t_stack *b,
	char *rule,
	t_bench_metrics *metrics
)
{
	if (ft_strncmp("ss", rule, 3) == 0)
	{
		stack_swap(a);
		stack_swap(b);
		metrics->ss++;
	}
	else if (ft_strncmp("rb", rule, 3) == 0)
	{
		stack_rotate(b);
		metrics->rb++;
	}
	else if (ft_strncmp("rr", rule, 3) == 0)
	{
		stack_rotate(a);
		stack_rotate(b);
		metrics->rr++;
	}
	else if (ft_strncmp("rra", rule, 4) == 0)
	{
		stack_rrotate(a);
		metrics->rra++;
	}
}

void	handler_3(
	t_stack *a,
	t_stack *b,
	char *rule,
	t_bench_metrics *metrics
)
{
	if (ft_strncmp("rrb", rule, 4) == 0)
	{
		stack_rrotate(b);
		metrics->rrb++;
	}
	else if (ft_strncmp("rrr", rule, 4) == 0)
	{
		stack_rrotate(a);
		stack_rrotate(b);
		metrics->rrr++;
	}
}

void	rules_handling(
	t_stack *a,
	t_stack *b,
	char *rule,
	t_bench_metrics *metrics
)
{
	handler_1(a, b, rule, metrics);
	handler_2(a, b, rule, metrics);
	handler_3(a, b, rule, metrics);
	ft_putendl_fd(rule, 1);
	metrics->operations++;
}

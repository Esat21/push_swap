/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:46:13 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/19 16:43:54 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Allocates and initializes a new stack.
 *
 * Dynamically allocates memory for a `t_stack` structure and initializes 
 * its members (`first` and `last` to `NULL`, and `size` to `0`).
 *
 * @return A pointer to the newly allocated and initialized `t_stack` 
 * on success.
 * @retval NULL If memory allocation fails.
 */
t_stack	*init_stack(void)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->first = NULL;
	lst->last = NULL;
	lst->size = 0;
	lst->flags = NULL;
	lst->metrics = NULL;
	return (lst);
}

t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->is_adaptive = 1;
	flags->is_simple = 0;
	flags->is_medium = 0;
	flags->is_complex = 0;
	flags->is_bench = 0;
	return (flags);
}

t_stack	*create_stack_a(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	stack_a = init_stack();
	stack_a->flags = init_flags();
	stack_a->metrics = bench_metrics_init();
	i = -1;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
			continue ;
		stack_add_back(stack_a, newnode(ft_atoi(argv[i])));
	}
	return (stack_a);
}

t_bench_metrics	*bench_metrics_init(void)
{
	t_bench_metrics	*metrics;

	metrics = malloc(sizeof(t_bench_metrics));
	if (!metrics)
		return (NULL);
	metrics->operations = 0;
	metrics->sa = 0;
	metrics->sb = 0;
	metrics->ss = 0;
	metrics->pa = 0;
	metrics->pb = 0;
	metrics->ra = 0;
	metrics->rb = 0;
	metrics->rr = 0;
	metrics->rra = 0;
	metrics->rrb = 0;
	metrics->rrr = 0;
	metrics->disorder = 0;
	metrics->strategy = NULL;
	metrics->algorithm = NULL;
	return (metrics);
}

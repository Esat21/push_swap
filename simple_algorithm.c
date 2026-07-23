/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 00:00:00 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/23 00:00:00 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

typedef struct s_choice
{
	t_node			*node;
	unsigned int	idx_a;
	unsigned int	idx_b;
	unsigned int	cost;
}				t_choice;

static unsigned int	min_uint(unsigned int x, unsigned int y)
{
	if (x < y)
		return (x);
	return (y);
}

static void	evaluate_candidate(t_sort_ctx *ctx, t_node *node,
	unsigned int idx_a, t_choice *choice)
{
	unsigned int	idx_b;
	unsigned int	cost_a;
	unsigned int	cost_b;
	unsigned int	cost;

	cost_a = min_uint(idx_a, ctx->a->size - idx_a);
	idx_b = 0;
	cost_b = 0;
	if (ctx->b->size > 0)
	{
		idx_b = (unsigned int)get_index(ctx->b->first,
				find_target(ctx, node->normalised));
		cost_b = min_uint(idx_b, ctx->b->size - idx_b);
	}
	if ((idx_a * 2 <= ctx->a->size) == (idx_b * 2 <= ctx->b->size))
	{
		if (cost_a > cost_b)
			cost = cost_a;
		else
			cost = cost_b;
	}
	else
		cost = cost_a + cost_b;
	if (!choice->node || cost < choice->cost)
	{
		choice->node = node;
		choice->idx_a = idx_a;
		choice->idx_b = idx_b;
		choice->cost = cost;
	}
}

static t_choice	find_best_choice(t_sort_ctx *ctx)
{
	t_choice		choice;
	t_node			*curr;
	unsigned int	idx;

	choice.node = NULL;
	curr = ctx->a->first;
	idx = 0;
	while (curr)
	{
		evaluate_candidate(ctx, curr, idx, &choice);
		curr = curr->next;
		idx++;
	}
	return (choice);
}

static void	execute_choice(t_sort_ctx *ctx, t_choice *choice,
	t_bench_metrics *m)
{
	unsigned int	cost_a;
	unsigned int	cost_b;
	unsigned int	shared;
	int				fwd_a;
	int				fwd_b;

	cost_a = min_uint(choice->idx_a, ctx->a->size - choice->idx_a);
	cost_b = min_uint(choice->idx_b, ctx->b->size - choice->idx_b);
	fwd_a = (choice->idx_a * 2 <= ctx->a->size);
	fwd_b = (choice->idx_b * 2 <= ctx->b->size);
	shared = 0;
	if (fwd_a == fwd_b)
		shared = min_uint(cost_a, cost_b);
	rotate_both_n(ctx->a, ctx->b, fwd_a, shared, m);
	rotate_a_n(ctx->a, ctx->b, fwd_a, cost_a - shared, m);
	rotate_b_n(ctx->a, ctx->b, fwd_b, cost_b - shared, m);
	rules_handling(ctx->a, ctx->b, "pb", m);
}

void	insertion_sort(t_stack *a, t_stack *b, t_bench_metrics *m)
{
	t_sort_ctx		ctx;
	t_choice		choice;
	unsigned int	total;
	unsigned int	idx;

	total = a->size;
	if (total == 0)
		return ;
	ctx.a = a;
	ctx.b = b;
	ctx.b_min = 0;
	ctx.b_max = 0;
	while (a->size > 0)
	{
		choice = find_best_choice(&ctx);
		if (b->size == 0 || choice.node->normalised > ctx.b_max)
			ctx.b_max = choice.node->normalised;
		if (b->size == 0 || choice.node->normalised < ctx.b_min)
			ctx.b_min = choice.node->normalised;
		execute_choice(&ctx, &choice, m);
	}
	if (b->size > 0)
	{
		idx = (unsigned int)get_index(b->first, total - 1);
		if (idx * 2 <= b->size)
			rotate_b_n(a, b, 1, idx, m);
		else
			rotate_b_n(a, b, 0, b->size - idx, m);
	}
	while (b->size > 0)
		rules_handling(a, b, "pa", m);
}

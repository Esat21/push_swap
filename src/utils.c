/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:18:32 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/06 15:18:32 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_n_times(t_stack *a, t_stack *b, int n, char *rule)
{
	int	i;

	i = 0;
	while (i++ < n)
		rules_handling(a, b, rule);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		i;
	long	sign;

	res = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '-' )
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += (long)nptr[i++] - 48;
	}
	res *= sign;
	return (res);
}

void	print_bench(t_bench_metrics *m)
{
	int	disorder;

	disorder = m->disorder * 10000;
	ft_printf_fd(
		2, "[bench] disorder:\t%d.%d%%\n", disorder / 100, disorder % 100);
	ft_printf_fd(2, "[bench] strategy:\t%s / %s\n", m->strategy, m->algorithm);
	ft_printf_fd(2, "[bench] total_ops:\t%d\n", m->operations);
	ft_printf_fd(
		2,
		"[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\tpb:\t%d\n",
		m->sa, m->sb, m->ss, m->pa, m->pb);
	ft_printf_fd(
		2,
		"[bench] ra:\t%d\trb:\t%d\trr:\t%d\trra:\t%d\trrb:\t%d\trrr:\t%d\n",
		m->ra, m->rb, m->rr, m->rra, m->rrb, m->rrr);
}

// For testing:
// void	print_stack(t_stack *stack)
// {
// 	t_node	*curr;

// 	curr = stack->first;
// 	while (curr)
// 	{
// 		ft_printf_fd(1, "%d ", curr->value);
// 		curr = curr->next;
// 	}
// 	ft_printf_fd(1, "\n");
// }

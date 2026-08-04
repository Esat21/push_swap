/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bemch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:31:23 by ssokhats          #+#    #+#             */
/*   Updated: 2026/08/04 12:31:23 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_bench_metrics *m)
{
	int	disorder;

	disorder = m->disorder * 10000;
	ft_printf_fd(
		2, "[bench] disorder:\t%d.%d%%\n", disorder / 100, disorder % 100
	);
	ft_printf_fd(2, "[bench] strategy:\t%s / %s\n", m->strategy, m->algorithm);
	ft_printf_fd(2, "[bench] total_ops:\t%d\n", m->operations);
	ft_printf_fd(
		2,
		"[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\tpb:\t%d\n",
		m->sa, m->sb, m->ss, m->pa, m->pb
	);
	ft_printf_fd(
		2,
		"[bench] ra:\t%d\trb:\t%d\trr:\t%d\trra:\t%d\trrb:\t%d\trrr:\t%d\n",
		m->ra, m->rb, m->rr, m->rra, m->rrb, m->rrr
	);
}

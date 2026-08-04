/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_collection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 12:14:45 by ssokhats          #+#    #+#             */
/*   Updated: 2026/08/01 12:14:45 by ssokhats         ###   ########.fr       */
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
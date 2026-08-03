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

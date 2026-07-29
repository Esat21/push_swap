/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:43:08 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/29 21:54:04 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *s)
{
	int	is_flag;

	is_flag = 0;
	if (!ft_strncmp(s, "--simple", 9))
		is_flag = 1;
	else if (!ft_strncmp(s, "--medium", 9))
		is_flag = 1;
	else if (!ft_strncmp(s, "--complex", 10))
		is_flag = 1;
	else if (!ft_strncmp(s, "--adaptive", 11))
		is_flag = 1;
	return (is_flag);
}

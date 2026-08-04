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
	const char	*flags[] = {
		"--simple", "--medium", "--complex", "--adaptive", "--bench"
	};
	int			i;

	i = -1;
	while (++i < 5)
	{
		if (!ft_strncmp(flags[i], s, ft_strlen(flags[i]) + 1))
			return (1);
	}
	return (0);
}

void	set_flag(char *s, t_flags *flags)
{
	if (!ft_strncmp("--adaptive", s, 11))
		flags->is_adaptive = 1;
	else if (!ft_strncmp("--medium", s, 9))
		flags->is_medium = 1;
	else if (!ft_strncmp("--complex", s, 10))
		flags->is_complex = 1;
	else if (!ft_strncmp("--simple", s, 9))
		flags->is_simple = 1;
	else if (!ft_strncmp("--bench", s, 8))
		flags->is_bench = 1;
}

int	find_flags(int argc, char **argv, t_flags *flags)
{
	int	i;
	int	t;

	i = -1;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
			set_flag(argv[i], flags);
	}
	t = flags->is_simple + flags->is_medium + flags->is_complex;
	if (t > 1)
		return (0);
	return (1);
}

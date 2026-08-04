/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:19:08 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/30 22:19:08 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strncmp(argv[i], argv[j], ft_strlen(argv[i]) + 1))
				return (0);
			j++;
		}
	}
	return (1);
}

int	is_allnum(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
			continue ;
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-'
				&& argv[i][j] != '+')
				return (0);
			j++;
		}
	}
	return (1);
}

int	is_in_range(int argc, char **argv)
{
	int	i;

	i = -1;
	while (i++ < argc - 1)
	{
		if (is_flag(argv[i]))
			continue ;
		if (ft_strlen(argv[i]) > 11 ||
			(ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN))
			return (0);
	}
	return (1);
}

int	input_check(int argc, char **argv)
{
	if (!is_unique(argc, argv) || !is_allnum(argc, argv) || !is_in_range(argc, argv))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}

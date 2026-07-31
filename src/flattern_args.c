/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flattern_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:46:06 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/31 12:46:06 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int count_tokens(int argc, char **argv)
{
	int		i;
	int		count;
	char	**split;
	int		j;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		// if (is_flag(argv[i]))
		// 	continue ;
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_split(split);
	}
	return (count);
}

char	**flatten_args(int argc, char **argv, int *total_nums)
{
	char	**flat;
	char	**split;
	int		i;
	int		j;
	int		k;

	*total_nums = count_tokens(argc, argv);
	if (*total_nums == 0)
		return (NULL);
	flat = malloc(sizeof(char *) * (*total_nums + 1));
	if (!flat)
		return (NULL);
	i = 0;
	k = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split && split[j])
			flat[k++] = split[j++];
		free(split);
	}
	flat[k] = NULL;
	return (flat);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:49:35 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/03 19:49:22 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static char	*buffer_append(char *content, int total, char *buf, int bytes)
{
	char	*result;
	int		i;

	result = malloc(total + bytes + 1);
	if (!result)
	{
		free(content);
		return (NULL);
	}
	i = -1;
	while (++i < total)
		result[i] = content[i];
	i = -1;
	while (++i < bytes)
		result[total + i] = buf[i];
	result[total + bytes] = '\0';
	free(content);
	return (result);
}

static char	**rules_split(char *rules)
{
	char	**rules_splitted;

	rules_splitted = ft_split(rules, '\n');
	if (!rules_splitted)
		return (NULL);
	return (rules_splitted);
}

char	**read_rules(int argc)
{
	char	**rules;
	int		bytes;
	int		total;
	char	*content;
	char	buf[2048];

	content = NULL;
	rules = NULL;
	total = 0;
	if (argc > 1)
	{
		bytes = read(0, buf, 2048);
		while (bytes > 0)
		{
			content = buffer_append(content, total, buf, bytes);
			if (!content)
				break ;
			total += bytes;
			bytes = read(0, buf, 2048);
		}
		if (content)
			rules = rules_split(content);
	}
	free(content);
	return (rules);
}

int	apply_moves(t_stack *a, t_stack *b, char **moves)
{
	int	i;

	i = -1;
	while (moves && moves[++i])
	{
		if (rules_handling_checker(a, b, moves[i]) == 0)
		{
			ft_printf_fd(2, "Error\n");
			return (0);
		}
	}
	return (1);
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

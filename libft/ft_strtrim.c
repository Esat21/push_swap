/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:11:13 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/23 19:43:18 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	is_char_in_str(char const *set, char const chr)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == chr)
			return (1);
	}
	return (0);
}

char	*trim_begining(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (is_char_in_str(set, s1[i]))
		i++;
	return ((char *)&s1[i]);
}

char	*trim_from_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (is_char_in_str(set, s1[i]))
	{
		if (i == 0)
			break ;
		i--;
	}
	return ((char *)&s1[i]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*res;
	int		res_len;

	start = trim_begining(s1, set);
	end = trim_from_end(s1, set);
	res_len = end - start + 2;
	if (end < start)
		return (ft_strdup(""));
	res = (char *)malloc((res_len) * sizeof(char));
	ft_strlcpy(res, start, res_len);
	return (res);
}

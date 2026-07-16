/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:49:07 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/21 15:33:37 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**create_table(char const *s, char c)
{
	char	**res;
	int		nb_of_lines;
	int		is_str;
	int		i;

	is_str = 0;
	nb_of_lines = 0;
	i = -1;
	while (s[++i])
	{
		if (!is_str && s[i] != c)
		{
			is_str = 1;
			nb_of_lines++;
		}
		else if (is_str && s[i] == c)
			is_str = 0;
	}
	res = (char **)malloc((nb_of_lines + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[nb_of_lines] = NULL;
	return (res);
}

char	**ft_free_tab(char **tab, int size)
{
	while (size > 0)
		free(tab[--size]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		strnum;
	int		len;

	res = create_table(s, c);
	if (!res)
		return (NULL);
	strnum = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (s[len] != c && s[len])
			len++;
		if (len != 0)
		{
			res[strnum] = (char *)malloc((len + 1) * sizeof(char));
			if (!res[strnum])
				return (ft_free_tab(res, strnum));
			ft_strlcpy(res[strnum++], s, len + 1);
		}
		s += len;
	}
	return (res);
}

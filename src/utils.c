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

char	*ft_strjoin_wnl(char const *s1, char const *s2)
{
	char	*res;
	size_t	total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 2;
	res = (char *)malloc(sizeof(char) * (total_size));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, total_size);
	ft_strlcat(res, s2, total_size);
	ft_strlcat(res, "\n", total_size);
	return (res);
}

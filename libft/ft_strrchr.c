/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:01:02 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/23 19:43:03 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		i;

	res = NULL;
	i = -1;
	while (s[++i])
	{
		if (s[i] == (unsigned char)c)
			res = (char *)&s[i];
	}
	if (s[i] == c)
		res = (char *)&s[i];
	return (res);
}

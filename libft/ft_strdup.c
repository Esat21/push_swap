/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:48:56 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/21 11:57:34 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	s_len;

	s_len = ft_strlen(s);
	res = malloc(sizeof(char) * s_len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, s_len + 1);
	return (res);
}

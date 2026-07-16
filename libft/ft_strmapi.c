/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:29:29 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/22 12:49:54 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;
	size_t	strsize;

	strsize = ft_strlen(s);
	res = (char *)malloc((strsize + 1) * sizeof(char));
	i = 0;
	while (i < strsize)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

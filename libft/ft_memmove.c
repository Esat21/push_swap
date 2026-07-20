/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:48:56 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/23 17:29:02 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*res;
	char	*source;

	res = (char *)dest;
	source = (char *)src;
	if (!n)
		return (res);
	else if (src < dest)
	{
		while (1)
		{
			n--;
			res[n] = source[n];
			if (n == 0)
				break ;
		}
	}
	else
		res = ft_memcpy(dest, src, n);
	return ((void *)res);
}

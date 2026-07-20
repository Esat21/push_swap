/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:28:03 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/23 13:27:56 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*res;
	char	*source;

	res = (char *)dest;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		res[i] = source[i];
		i++;
	}
	return (res);
}

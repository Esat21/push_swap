/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 20:02:52 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/23 15:23:42 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	char	*start;

	start = dst;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen > size)
		return (srclen + size);
	while (*dst)
		dst++;
	i = dstlen;
	while (*src && ++i < size)
		*dst++ = *src++;
	*dst = '\0';
	dst = start;
	return (dstlen + srclen);
}

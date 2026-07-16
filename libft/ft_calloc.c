/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:18:32 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/24 14:17:22 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (ULONG_MAX / nmemb < size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	return (ft_bzero(res, nmemb * size));
}

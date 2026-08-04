/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:39:10 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/22 11:42:35 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	size;

	if (!s)
		return (write(fd, "(null)", 6));
	size = 0;
	i = -1;
	while (s[++i])
		size += write(fd, &s[i], 1);
	return (size);
}

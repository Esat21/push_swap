/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:45:09 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/23 19:16:25 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10 * -1, fd);
		ft_putchar_fd(n % 10 * -1 + 48, fd);
	}
	else if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else if (n / 10 == 0)
		ft_putchar_fd(n % 10 + 48, fd);
}

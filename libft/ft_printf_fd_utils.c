/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:34:43 by ssokhats          #+#    #+#             */
/*   Updated: 2026/08/04 11:34:43 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_base_fd(unsigned long long n, char *base, int nbase, int fd)
{
	int		size;

	size = 0;
	if (n / nbase > 0)
	{
		size += ft_putunbr_base_fd(n / nbase, base, nbase, fd);
		size += ft_putchar_fd(base[n % nbase], fd);
	}
	else if (n / nbase == 0)
		size += ft_putchar_fd(base[n % nbase], fd);
	return (size);
}

int	ft_putnbr_base_fd(long long n, char *base, int nbase, int fd)
{
	int		size;
	
	size = 0;
	if (n < 0)
	{
		size += ft_putchar_fd('-', fd);
		if (n / nbase != 0)
			size += ft_putnbr_base_fd(n / nbase * -1, base, nbase, fd);
		size += ft_putchar_fd(base[n % nbase * -1], fd);
	}
	else if (n / nbase > 0)
	{
		size += ft_putnbr_base_fd(n / nbase, base, nbase, fd);
		size += ft_putchar_fd(base[n % nbase], fd);
	}
	else if (n / nbase == 0)
		size += ft_putchar_fd(base[n % nbase], fd);
	return (size);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long long	n;
	int					size;

	if (!ptr)
		return (write(fd, "(nil)", 5));
	n = (unsigned long long)ptr;
	size = 0;
	size += write(fd, "0x", 2);
	size += ft_putunbr_base_fd(n, "0123456789abcdef", 16, fd);
	return (size);
}

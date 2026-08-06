/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:28:39 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/26 23:39:49 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_command(va_list *args, char c, int fd)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*args, int), fd));
	if (c == 's')
		return (ft_putstr_fd(va_arg(*args, char *), fd));
	if (c == 'p')
		return (ft_putptr_fd(va_arg(*args, void *), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_base_fd(va_arg(*args, int), "0123456789", 10, fd));
	if (c == 'u')
		return (
			ft_putunbr_base_fd(
				va_arg(*args, unsigned int), "0123456789", 10, fd));
	if (c == 'x')
		return (
			ft_putunbr_base_fd(va_arg(*args, unsigned int),
				"0123456789abcdef", 16, fd));
	if (c == 'X')
		return (
			ft_putunbr_base_fd(va_arg(*args, unsigned int),
				"0123456789ABCDEF", 16, fd));
	if (c == '%')
		return (write(fd, "%", 1));
	return (0);
}

int	ft_printf_fd(int fd, const char *s, ...)
{
	va_list	args;
	int		i;
	int		size;

	va_start(args, s);
	i = -1;
	size = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			size += ft_check_command(&args, s[i + 1], fd);
			i++;
			continue ;
		}
		size += write(fd, &s[i], 1);
	}
	va_end(args);
	return (size);
}

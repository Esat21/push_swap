/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:19:43 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/21 17:29:01 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_digits(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

void	fill_str(char *s, int index, int *n, int n_len)
{
	int	digit;

	if (index >= n_len)
	{
		return ;
	}
	fill_str(s, index + 1, n, n_len);
	digit = *n % 10;
	*n /= 10;
	if (digit < 0)
	{
		digit *= -1;
		*n *= -1;
	}
	s[index] = (char)digit + 48;
}

char	*ft_itoa(int n)
{
	char	*res;
	int		n_len;

	n_len = count_digits(n);
	if (n < 0)
		n_len++;
	res = (char *)malloc((n_len + 1) * sizeof(char));
	res[n_len] = 0;
	if (n < 0)
	{
		res[0] = '-';
		fill_str(res, 1, &n, n_len);
	}
	else
		fill_str(res, 0, &n, n_len);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:41:34 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/24 14:48:54 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c == -1)
		return (-1);
	if ((unsigned char)c > 96 && (unsigned char)c < 123)
		return ((unsigned char)c - 32);
	return ((unsigned char)c);
}

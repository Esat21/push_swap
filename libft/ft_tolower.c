/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:47:09 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/24 14:47:41 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c == -1)
		return (-1);
	if ((unsigned char)c > 64 && (unsigned char)c < 91)
		return ((unsigned char)c + 32);
	return ((unsigned char)c);
}

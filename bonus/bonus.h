/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:36:02 by esyaman           #+#    #+#             */
/*   Updated: 2026/08/03 19:01:39 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define BUFFER_SIZE 7

char			*get_next_line(int fd);

unsigned	int	ft_strlcat(char *dest, const char *src, size_t size);

size_t			ft_strlen(const char *s);

size_t			ft_strlcpy(char *dest, const char *src, size_t n);

int				ft_strchr_n(const char *s, int c);

#endif
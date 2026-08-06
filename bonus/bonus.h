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
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	unsigned int	normalised;
}			t_node;

typedef struct s_stack
{
	t_node			*first;
	t_node			*last;
	unsigned int	size;
}			t_stack;

// checker_rules.c
void	rules_handling_checker(t_stack *a, t_stack *b, char *rule);

// checker_utils.c
char	**read_rules(void);
void	apply_moves(t_stack *a, t_stack *b, char **moves);

#endif
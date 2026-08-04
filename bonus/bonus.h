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
# include "../include/push_swap.h"

char	**read_rules();

int		checker_bonus(int argc, char **argv);

void	apply_moves(t_stack *a, t_stack *b, char **moves);

void	rules_handling_checker(t_stack *a, t_stack *b, char *rule);



#endif
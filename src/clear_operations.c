/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esyaman <esyaman@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:42:22 by ssokhats          #+#    #+#             */
/*   Updated: 2026/07/19 17:07:33 by esyaman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Frees all nodes in a linked list and nullifies the head pointer.
 *
 * Sequentially iterates through the linked list starting at `*lst`, freeing
 * the memory allocated for each individual node. Once all nodes have been
 * deallocated, the caller's original head pointer is set to `NULL` to prevent
 * dangling pointer bugs.
 *
 * @param lst A pointer to the head pointer of the linked list to be freed.
 */
static void	free_lst(t_node **lst)
{
	t_node	*curr;
	t_node	*next;

	if (!lst || !*lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

static void	free_metrics(t_bench_metrics **metrix)
{
	free((*metrix)->strategy);
	free((*metrix)->algorithm);
	free(*metrix);
	*metrix = NULL;
}

/**
 * @brief Safely frees two stacks and their nodes independently.
 *
 * Deallocates all memory associated with stacks `a` and `b`. The function 
 * checks each stack independently; if one stack is valid, it frees all of 
 * its internal nodes, nullifies its pointers, and deallocates the stack 
 * container itself before setting the caller's pointer to `NULL`. 
 *
 * @param a A pointer to the head pointer of stack A.
 * @param b A pointer to the head pointer of stack B.
 */
void	free_stacks(t_stack **a, t_stack **b)
{
	if (a && *a)
	{
		if ((*a)->metrics)
			free_metrics(&(*a)->metrics);
		if ((*a)->flags)
			free((*a)->flags);
		free_lst(&((*a)->first));
		(*a)->last = NULL;
		free(*a);
		*a = NULL;
	}
	if (b && *b)
	{
		free_lst(&((*b)->first));
		(*b)->last = NULL;
		free(*b);
		*b = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:45:45 by esyaman           #+#    #+#             */
/*   Updated: 2026/07/17 11:22:19 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Creates and initializes a new stack node.
 *
 * Allocates memory for a new node of type `t_node`, assigns the provided 
 * integer value to its `value` member, and initializes the `next` pointer 
 * to `NULL`.
 *
 * @param value The integer value to be stored in the new node.
 * * @return A pointer to the newly allocated `t_node` on success.
 * @retval NULL If memory allocation fails.
 */
t_node	*newnode(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->normalized = 0;
	return (new_node);
}

/**
 * @brief Allocates and initializes a new stack.
 *
 * Dynamically allocates memory for a `t_stack` structure and initializes 
 * its members (`first` and `last` to `NULL`, and `size` to `0`).
 *
 * @return A pointer to the newly allocated and initialized `t_stack` 
 * on success.
 * @retval NULL If memory allocation fails.
 */
t_stack	*init_stack(void)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->first = NULL;
	lst->last = NULL;
	lst->size = 0;
	return (lst);
}

/**
 * @brief Appends a new node to the end (bottom) of the stack.
 *
 * This function adds the node `new` to the end of the stack pointed to by 
 * `lst`. If the stack is currently empty, the node becomes both the first and 
 * last element. It also handles updating the stack's size and links. If either
 *  `lst` or `new` is `NULL`, the function returns immediately without making 
 * changes.
 *
 * @param lst A pointer to the stack structure.
 * @param new A pointer to the new node to be added to the stack.
 */
void	stack_add_back(t_stack *lst, t_node *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (lst->first == NULL)
	{
		lst->first = new;
		lst->last = new;
		lst->size++;
		return ;
	}
	lst->last->next = new;
	lst->last = new;
	lst->size++;
}

/**
 * @brief Inserts a new node at the beginning (top) of the stack.
 *
 * This function prepends the node `new` to the front of the stack pointed
 * to by `lst`. If the stack is empty, it initializes both `first` and
 * `last` pointers to the new node. Otherwise, it links the new node to
 * the current top of the stack. In both cases, the stack size is
 * incremented. If either `lst` or `new` is `NULL`, the function returns
 * immediately.
 *
 * @param lst A pointer to the stack structure.
 * @param new A pointer to the new node to be inserted at the front.
 */
void	stack_add_front(t_stack *lst, t_node *new)
{
	if (new == NULL || lst == NULL)
		return ;
	{
		lst->first = new;
		lst->last = new;
		lst->size++;
		return ;
	}
	new->next = lst->first;
	lst->first = new;
	lst->size++;
}

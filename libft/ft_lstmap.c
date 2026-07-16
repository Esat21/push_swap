/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssokhats <ssokhats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:13:29 by ssokhats          #+#    #+#             */
/*   Updated: 2026/06/24 12:49:09 by ssokhats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*curr;
	t_list	*new;

	curr = lst;
	if (curr && f && del)
	{
		res = ft_lstnew(f(curr->content));
		if (!res)
			return (NULL);
		curr = curr->next;
	}
	while (curr)
	{
		new = ft_lstnew(f(curr->content));
		if (!new)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		curr = curr->next;
	}
	return (res);
}

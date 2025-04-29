/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:54:51 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/12 14:29:59 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*t;

	if (!lst || !f)
		return (0);
	result = ft_lstnew((*f)(lst->content));
	if (!result)
		return (0);
	t = result;
	lst = lst->next;
	while (lst)
	{
		result -> next = ft_lstnew((*f)(lst->content));
		if (!result->next)
		{
			ft_lstclear(&t, del);
			return (0);
		}
		result = result->next;
		lst = lst->next;
	}
	result->next = NULL;
	return (t);
}

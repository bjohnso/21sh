/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:44:54 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:44:55 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*ret;

	node = f(lst);
	ret = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = f(lst);
		node = node->next;
	}
	return (ret);
}

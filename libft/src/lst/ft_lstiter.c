/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:44:59 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:00 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	f(lst);
	while (lst->next)
	{
		lst = lst->next;
		f(lst);
	}
}

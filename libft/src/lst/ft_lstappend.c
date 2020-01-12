/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:19 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:20 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "libft.h"
#include <stddef.h>

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*node;

	if (alst == NULL)
		return ;
	node = *alst;
	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	else
		*alst = new;
}

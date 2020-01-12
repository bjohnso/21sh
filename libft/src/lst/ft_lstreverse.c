/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:44:49 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:44:49 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

t_list	*ft_lstreverse(t_list **head)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	if (head)
	{
		while (*head)
		{
			next = (*head)->next;
			(*head)->next = prev;
			prev = *head;
			*head = next;
		}
		*head = prev;
	}
	return (prev);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:17 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:18 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_if(t_list **alst, void *data_ref, int (*cmp)(),
					void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	**indirect;

	indirect = alst;
	while (*indirect)
	{
		if ((*cmp)((*indirect)->content, data_ref) == 0)
		{
			tmp = (*indirect);
			(*indirect) = (*indirect)->next;
			ft_lstdelone(&tmp, del);
		}
		else
			indirect = &(*indirect)->next;
	}
}

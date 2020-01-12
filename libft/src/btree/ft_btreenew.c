/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:39:35 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:55:21 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stddef.h>

t_btree	*ft_btreenew(void const *content, size_t content_size)
{
	t_btree *new;

	new = (t_btree *)ft_memalloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(content_size + 1);
		new->content_size = content_size;
		ft_memcpy(new->content, content, content_size);
	}
	return (new);
}

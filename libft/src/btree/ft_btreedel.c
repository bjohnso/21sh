/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:54:26 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:54:27 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	ft_btreedel(t_btree **root, void (*del)(void *, size_t))
{
	if (root && *root && del)
	{
		ft_btreedel((*root)->left, del);
		ft_btreedel((*root)->right, del);
		ft_btreedelone((*root), del);
	}
}

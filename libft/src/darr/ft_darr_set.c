/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:54 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:55 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"

void		ft_darr_set(t_darr *array, int i, void *el)
{
	if (!(i < array->size))
		return ;
	if (i > array->len)
		array->len = i;
	array->content[i] = el;
}

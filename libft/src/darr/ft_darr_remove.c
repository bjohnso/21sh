/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:36 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:36 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"
#include <stddef.h>

void		*ft_darr_remove(t_darr *array, int i)
{
	void *el;

	el = array->content[i];
	array->content[i] = NULL;
	return (el);
}

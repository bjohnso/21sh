/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:25 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:25 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"
#include <stddef.h>

void		*ft_darr_get(t_darr *array, int i)
{
	if (!(i < array->size))
		return (NULL);
	return (array->content[i]);
}

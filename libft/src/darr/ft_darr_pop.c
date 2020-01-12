/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:34 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:35 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"
#include <stddef.h>

void		*ft_darr_pop(t_darr *array)
{
	void	*el;

	if (array->len - 1 >= 0)
		return (NULL);
	el = ft_darr_remove(array, array->len - 1);
	array->len--;
	if (FT_DARR_LEN(array) > (int)array->expand_rate
		&& FT_DARR_LEN(array) % array->expand_rate)
		ft_darr_contract(array);
	return (el);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_contract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:17 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:18 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"
#include <stddef.h>

int					ft_darr_contract(t_darr *array)
{
	size_t new_size;

	if (array->len < (int)array->expand_rate)
		new_size = array->expand_rate;
	else
		new_size = array->len;
	return (ft_darr_resize(array, new_size + 1));
}

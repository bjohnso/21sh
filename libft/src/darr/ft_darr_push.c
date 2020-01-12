/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:32 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:33 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"

int			ft_darr_push(t_darr *array, void *el)
{
	array->content[array->len] = el;
	array->len++;
	if (FT_DARR_LEN(array) >= FT_DARR_SIZE(array))
		return (ft_darr_expand(array));
	else
		return (0);
}

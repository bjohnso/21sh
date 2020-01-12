/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:31 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:31 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"
#include "libft.h"
#include <stddef.h>

void		*ft_darr_new(t_darr *array)
{
	if (!(array->content_size > 0))
		return (NULL);
	return (ft_memalloc(array->content_size));
}

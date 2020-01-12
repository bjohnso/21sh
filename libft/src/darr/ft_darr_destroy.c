/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:19 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:20 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"
#include <stdlib.h>

void		ft_darr_destroy(t_darr *array)
{
	if (array)
	{
		if (array->content)
			free(array->content);
		free(array);
	}
}

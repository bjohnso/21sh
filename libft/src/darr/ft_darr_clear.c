/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:14 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:15 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"
#include <stdlib.h>

void		ft_darr_clear(t_darr *array)
{
	int i;

	i = 0;
	if (array->content_size > 0)
	{
		while (i < array->len)
		{
			if (array->content[i] != NULL)
				free(array->content[i]);
			++i;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:48:11 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:48:11 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t src_size, size_t new_size)
{
	void *new_ptr;

	if (!new_size)
	{
		if (ptr)
			free(ptr);
		return (ptr);
	}
	if (!ptr)
		return (malloc(new_size));
	if (new_size <= src_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr)
	{
		ft_memcpy(new_ptr, ptr, src_size);
		free(ptr);
	}
	return (new_ptr);
}

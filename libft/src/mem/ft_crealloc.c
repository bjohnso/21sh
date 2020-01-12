/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:48:36 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:48:36 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "libft.h"

void	*ft_crealloc(void *ptr, int size)
{
	void	*new;

	new = ft_memalloc(size);
	ft_memcpy(new, ptr, ft_strlen(ptr));
	ft_memdel(&ptr);
	return (new);
}

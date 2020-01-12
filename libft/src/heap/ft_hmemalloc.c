/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmemalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:36 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:37 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include "libft.h"
#include <stddef.h>

void	*ft_hmemalloc(size_t size)
{
	void	*ptr;

	ptr = ft_hmalloc(size);
	ft_bzero(ptr, size);
	return (ptr);
}

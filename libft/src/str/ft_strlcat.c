/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:51:10 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:51:10 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t returnval;

	if (size + ft_strlen(src) > ft_strlen(src) + ft_strlen(dst))
		returnval = ft_strlen(src) + ft_strlen(dst);
	else
		returnval = ft_strlen(src) + size;
	while (*dst && size > 0)
	{
		dst++;
		size--;
	}
	if (size < 1)
		return (returnval);
	size--;
	while (*src && size > 0)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (returnval);
}

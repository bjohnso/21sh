/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:48:28 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:48:28 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n--)
	{
		if (*str == chr)
			return (str);
		++str;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:48:13 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:48:14 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char chr;
	unsigned char *str;

	chr = c & 0xff;
	str = (unsigned char *)b;
	while (len--)
		*str++ = chr;
	return (b);
}

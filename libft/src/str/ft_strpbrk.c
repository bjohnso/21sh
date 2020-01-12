/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:50:33 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:50:33 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strpbrk(const char *s, const char *charset)
{
	char	*c;

	while (*s)
	{
		c = (char *)charset;
		while (*c)
		{
			if (*c == *s)
				return ((char *)s);
			c++;
		}
		s++;
	}
	return (NULL);
}

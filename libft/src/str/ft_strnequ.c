/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:50:40 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:50:41 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while ((*s1 || *s2) && n--)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenrchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:51:02 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:51:02 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlenrchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (0);
}

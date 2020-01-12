/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:51:05 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:51:05 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlenchr(char *str, char c)
{
	size_t i;

	i = 0;
	while (*str && *(str++) != c)
	{
		i++;
	}
	return (i);
}

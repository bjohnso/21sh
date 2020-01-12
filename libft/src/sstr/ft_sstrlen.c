/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:52:03 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:52:04 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_sstrlen(char *const sstr[])
{
	size_t i;

	i = 0;
	while (sstr[i])
		i++;
	return (i);
}

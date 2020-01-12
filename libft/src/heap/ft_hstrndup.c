/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:29 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:29 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include <stddef.h>

char		*ft_hstrndup(char *hstr, size_t size)
{
	char	*ret;
	size_t	i;

	if (!hstr)
		return (NULL);
	ret = (char*)ft_hmalloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = -1;
	while (++i < size)
		ret[i] = hstr[i];
	return (ret);
}

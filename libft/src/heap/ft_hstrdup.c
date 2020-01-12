/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:31 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:32 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_hstrdup(char *hstr)
{
	char	*ret;
	size_t	size;
	size_t	i;

	if (!hstr)
		return (NULL);
	size = -1;
	while (hstr[++size])
		;
	ret = (char*)ft_hmalloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = -1;
	while (++i < size)
		ret[i] = hstr[i];
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:52:01 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:52:02 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_sstrpush(char **sstr, char *str)
{
	char	**ret;
	int		size;

	size = 0;
	if (sstr)
		while (sstr[size])
			size++;
	ret = (char **)ft_memalloc(sizeof(char *) * (size + 2));
	if (!ret)
		return (NULL);
	if (sstr)
		ft_memcpy(ret, sstr, sizeof(char *) * size);
	ret[size] = ft_strdup(str);
	ret[size + 1] = NULL;
	free(sstr);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:50:12 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:50:13 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_getenv(char **env, char *key)
{
	if (!env)
		return (NULL);
	while (*env)
	{
		if (ft_strcmp(*env, key) == '=' &&
			ft_strlen(key) == ft_strlenchr(*env, '='))
			return (*env + ft_strlen(key) + 1);
		env++;
	}
	return (NULL);
}

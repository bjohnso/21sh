/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:50:55 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:50:55 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || (str = ft_strnew(ft_strlen(s))) == 0)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

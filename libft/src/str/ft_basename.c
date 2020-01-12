/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:51:58 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:51:58 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_basename(const char *path)
{
	char *basename;

	basename = ft_strrchr(path, '/');
	return ((basename) ? basename + 1 : (char *)path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:50:09 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:50:10 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>

int	ft_isdir(const char *path)
{
	struct stat	sb;

	if (stat(path, &sb))
		return (0);
	return (S_ISDIR(sb.st_mode));
}

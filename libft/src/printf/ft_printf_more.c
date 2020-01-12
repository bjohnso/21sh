/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:52:15 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:52:16 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_p.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_asprintf(char **ret, const char *format, ...)
{
	va_list ap;
	int		len;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	len = ft_vasprintf(ret, format, ap);
	if (len < 0)
		return (-1);
	va_end(ap);
	return (len);
}

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		len;
	char	*ret;

	if (!format || !*format || fd < 0)
		return (0);
	len = ft_vasprintf(&ret, format, ap);
	if (write(fd, ret, len) < 0)
		return (-1);
	free(ret);
	return (len);
}

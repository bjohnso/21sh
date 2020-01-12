/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:39:39 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:39:39 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_getchar(void)
{
	static char	buf[BUFSIZ];
	static char	*bufp = buf;
	static int	n = 0;

	if (n == 0)
	{
		n = read(STDIN_FILENO, buf, sizeof(buf));
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}

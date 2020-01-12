/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_win_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:46:16 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:46:16 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/ioctl.h>

void	ft_get_win_size(int *x, int *y)
{
	struct winsize win;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
	if (x)
		*x = win.ws_col;
	if (y)
		*y = win.ws_row;
}

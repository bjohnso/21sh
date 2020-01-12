/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_goto.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:46:18 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:46:19 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <term.h>
#include <stddef.h>
#include <unistd.h>

void	ft_cursor_goto(int x, int y)
{
	char *str1;
	char *str2;

	if ((str1 = tgetstr("cm", NULL)) != NULL)
	{
		if ((str2 = tgoto(str1, x, y)) != NULL)
			ft_putstr_fd(str2, STDERR_FILENO);
	}
}

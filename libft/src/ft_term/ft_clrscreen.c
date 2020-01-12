/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clrscreen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:46:21 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:46:21 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term_private.h"

void	ft_clrscreen(int rows)
{
	while (--rows >= 0)
	{
		ft_cursor_goto(0, rows);
		ft_termcmd("dl");
	}
}

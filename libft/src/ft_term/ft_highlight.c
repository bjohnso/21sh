/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_highlight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:46:13 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:46:14 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term_private.h"
#include <stdbool.h>

void	ft_highlight(bool set)
{
	if (set == true)
		ft_termcmd("so");
	else if (set == false)
		ft_termcmd("se");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_underline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:43:05 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:53 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term_private.h"
#include <stdbool.h>

void	ft_underline(bool set)
{
	if (set == true)
		ft_termcmd("us");
	else if (set == false)
		ft_termcmd("ue");
}

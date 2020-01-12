/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:52:09 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:52:10 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

void	ft_sstrdel(char ***sstr)
{
	size_t i;

	if (!sstr)
		return ;
	i = 0;
	while ((*sstr)[i])
	{
		ft_strdel((*sstr) + i);
		i++;
	}
	ft_strdel((*sstr) + i);
	free(*sstr);
	*sstr = NULL;
}

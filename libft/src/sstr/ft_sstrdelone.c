/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:52:07 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:52:07 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void	ft_sstrdelone(char **sstr, int index)
{
	int i;

	ft_strdel(&sstr[index]);
	i = index;
	while (sstr[i] || i == index)
	{
		sstr[i] = sstr[i + 1];
		i++;
	}
}

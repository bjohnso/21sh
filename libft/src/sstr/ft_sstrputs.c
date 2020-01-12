/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:52:00 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:52:00 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sstrputs(char **sstr)
{
	int i;

	if (!sstr || !*sstr)
		return ;
	i = 0;
	while (sstr[i])
	{
		ft_putendl(sstr[i]);
		i++;
	}
}

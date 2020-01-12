/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:58 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:58 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstr.h"
#include <stdlib.h>

void	ft_dstr_free(t_dstr *dstr)
{
	if (dstr->data && dstr->cap > 0)
	{
		free(dstr->data);
		dstr->data = NULL;
	}
}

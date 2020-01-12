/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:56 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:56 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstr.h"
#include "libft.h"
#include <stddef.h>

void	ft_dstr_append(t_dstr *dstr, char *newdata)
{
	size_t nd_len;

	if (!newdata || !newdata[0])
		return ;
	nd_len = ft_strlen(newdata);
	if (dstr->cap < dstr->len + nd_len)
		ft_dstr_resize(dstr, dstr->len + nd_len);
	ft_memcpy(dstr->data + dstr->len, newdata, nd_len);
	dstr->len += nd_len;
}

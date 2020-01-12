/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_nappend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:59 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:43:00 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstr.h"
#include "libft.h"
#include <stddef.h>

void	ft_dstr_nappend(t_dstr *dstr, char *newdata, size_t n)
{
	size_t nd_len;

	if (n == 0 || !newdata || !newdata[0])
		return ;
	nd_len = n;
	if (dstr->cap < dstr->len + nd_len)
		ft_dstr_resize(dstr, dstr->len + nd_len);
	ft_memcpy(dstr->data + dstr->len, newdata, nd_len);
	dstr->len += nd_len;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:43:03 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:43:03 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstr.h"
#include "libft.h"
#include <stddef.h>

void	ft_dstr_resize(t_dstr *dstr, size_t min)
{
	size_t	mllc_size;

	if (!(dstr->data))
		ft_dstr_new(dstr, min);
	mllc_size = dstr->cap;
	while (mllc_size < min)
		mllc_size *= 2;
	dstr->data = (char *)ft_memrealloc(dstr->data, dstr->len, mllc_size);
	dstr->cap = mllc_size;
}

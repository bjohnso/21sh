/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:48:09 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:48:09 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdlib.h>

void	ft_swap(void *a, void *b, size_t s)
{
	void	*tmp;

	tmp = malloc(s);
	ft_memcpy(tmp, a, s);
	ft_memcpy(a, b, s);
	ft_memcpy(b, tmp, s);
	free(tmp);
}

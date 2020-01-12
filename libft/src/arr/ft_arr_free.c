/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:54:04 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:54:05 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_arr_free(void **d_arr, int rows)
{
	while (--rows > -1)
	{
		free(d_arr[rows]);
	}
	free(d_arr);
}

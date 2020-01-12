/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:39:11 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:39:12 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_H
# define ARR_H

# include <stddef.h>

void	ft_arr_remove_nth(int nth, void *array, size_t size, int len);
void	ft_arr_free(void **d_arr, int rows);

#endif

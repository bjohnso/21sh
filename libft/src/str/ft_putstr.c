/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:51:39 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:51:40 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	if (s)
		write(STDOUT_FILENO, s, ft_strlen(s));
}

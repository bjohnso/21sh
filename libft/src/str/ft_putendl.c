/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:51:46 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:51:47 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "libft.h"

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

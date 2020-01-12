/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:46:23 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:46:24 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_usage(char const *name, char const *str)
{
	ft_dprintf(STDERR_FILENO, "%{bred}usage: %s%s%{eoc}\n", name, str);
	exit(EXIT_FAILURE);
}

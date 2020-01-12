/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:46:26 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:46:26 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_error_exit(const char *str)
{
	ft_dprintf(STDERR_FILENO, "%{bred}Error: %s%{eoc}\n", str);
	exit(EXIT_FAILURE);
}

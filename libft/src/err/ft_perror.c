/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:46:31 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:46:31 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	**g_argv = NULL;

int		ft_perror(char *name)
{
	name = name ? name : g_argv[0];
	return (0);
}

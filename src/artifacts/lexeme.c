/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:06:38 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 16:36:28 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

char		*new_lexeme(char *str, int len)
{
	char	*lexeme;

	lexeme = (char *)malloc(sizeof(char) * (len + 1));
	lexeme[len] = '\0';
	ft_strncpy(lexeme, str, len);
	return (lexeme);
}

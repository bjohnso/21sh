/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:09:09 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 17:28:06 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

int				is_delim(char *str)
{
	if (*str == ' ' || *str == '\t')
		return (0);
	return (-1);
}

char			*expand(char *lexeme, char *expansion, int pos)
{
	size_t	len;
	size_t	c;
	size_t	c_alt;
	char	*expanded;

	len = ft_strlen(lexeme) - 1 + ft_strlen(expansion);
	expanded = (char *)malloc(sizeof(char) * len + 1);
	expanded[len] = '\0';
	c = -1;
	c_alt = pos - 1;
	while (++c < len)
	{
		if (c < (size_t)pos)
			expanded[c] = lexeme[c];
		else
		{
			if (c == (size_t)pos)
				c = fill_alt(expanded, expansion, pos - 1, pos);
			else
				expanded[c] = lexeme[++pos];
		}
	}
	return (expand_return(lexeme, expanded));
}

int				fill_alt(char *expanded, char *expansion, size_t c, size_t pos)
{
	while (++c < ft_strlen(expansion))
		expanded[c] = expansion[c - pos];
	return (c);
}

char			*expand_return(char *lexeme, char *expanded)
{
	free(lexeme);
	if (!expanded)
	{
		free(expanded);
		return (NULL);
	}
	return (expanded);
}

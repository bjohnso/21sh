/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:18 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 12:33:38 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

/*
**Constructors
*/

t_token		*new_token(char *lexeme, int pos, char *type)
{
	t_token		*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->pos = pos;
	token->lexeme = lexeme;
	token->type = type;
	return (token);
}

/*
**Auxillary Functions
*/

t_token		*generate_token(char *lexeme, int pos)
{
	size_t	len;
	size_t	counter;

	if (pos == 0)
	{
		if (lexeme[0] != '/')
		{
			len = ft_strlen(lexeme);
			counter = -1;
			while (++counter < len)
			{
				if (lexeme[counter] == '/')
					return (new_token(lexeme, pos, "file"));
			}
		}
		return (new_token(lexeme, pos, "command"));
	}
	else
	{
		if (*lexeme == '-' && ft_strlen(lexeme) > 1)
			return (new_token(lexeme, pos, "option"));
		else
			return (new_token(lexeme, pos, "file"));
	}
}

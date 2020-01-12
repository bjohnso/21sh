/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:44 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 16:57:03 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

/*
**GLOBALS
*/

static int		g_input_len = 0;
static int		g_cursor = 0;

int				is_delim(char *str)
{
	if (*str == ' ' || *str == '\t')
		return (0);
	return (-1);
}

int				quote_lex(char *str)
{
	int		quote_count;
	int		len;

	quote_count = 0;
	len = 0;
	if (*str == '"')
	{
		if (g_cursor > 0)
			if (*(str - 1) == '\\')
				return (len);
		quote_count++;
		str++;
		g_cursor++;
		while (*str)
		{
			if (*str == '"')
				if (*(str - 1) != '\\')
					return (len);
			len++;
			str++;
			g_cursor++;
		}
	}
	if (quote_count == 0)
		return (len);
	else
		return (-1);
}

char			*space_lex(char *str)
{
	int		len;
	int		padding;

	len = 0;
	padding = 0;
	while (*str)
	{
		if (is_delim(str) == 0)
		{
			while (is_delim(str) == 0)
			{
				g_cursor++;
				str++;
				padding++;
			}
			break ;
		}
		else
			len++;
		g_cursor++;
		str++;
	}
	if (len > 0)
	{
		str = str - len - padding;
		return (new_lexeme(str, len));
	}
	return (NULL);
}

char			*lexer(char *expansion, char *str)
{
	char	*look;
	char	*lexeme;
	int		quote_len;
	int		exp_pos;

	look = str + g_cursor;
	while (*look)
	{
		quote_len = quote_lex(look);
		if (quote_len > 0)
			return (new_lexeme(look + 1, quote_len));
		else if (quote_len == -1)
			return (NULL);
		lexeme = space_lex(look);
		pos = 0;
		while (*lexeme)
		{
			if (*lexeme == '~')
			{
				lexeme = expand(lexeme - pos, expansion, pos);
				pos = 0;
			}
			pos++;
			lexeme++;
		}
		return (lexeme - pos);
	}
	return (NULL);
}

t_token_list	*parser(t_shell *shell, char *str)
{
	char			*lexeme;
	int				pos;
	t_token_list	*token_list;
	t_token			*temp;

	g_input_len = ft_strlen(str);
	g_cursor = 0;
	token_list = new_token_list();
	pos = 0;
	while (g_cursor < g_input_len)
	{
		if ((lexeme = lexer(environ_get_value(shell->environ,
			environ_search(shell->environ, "HOME", 4)), str)))
		{
			temp = generate_token(lexeme, pos);
			if (!temp)
			{
				free(temp);
				break ;
			}
			token_list_push(token_list, temp);
			pos++;
		}
	}
	return (token_list);
}

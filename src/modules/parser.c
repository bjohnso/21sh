/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:44 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 17:36:30 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

/*
**GLOBALS
*/

static int		g_pos = 0;
static char		*g_cursor;

int				quote_lex(void)
{
	int		quote_count;
	int		len;

	quote_count = 0;
	len = 0;
	if (g_cursor[g_pos] == '"')
	{
		if (g_pos > 0){
			if (g_cursor[g_pos - 1] == '\\')
			{
				g_pos++;
				return (len);
			}
		}
		quote_count++;
		g_pos++;
		while (g_cursor[g_pos])
		{
			if (g_cursor[g_pos] == '"')
			{
				if (g_cursor [g_pos - 1] != '\\')
				{
					g_pos++;
					return (len);
				}
			}
			len++;
			g_pos++;
		}
	}
	if (quote_count == 0)
		return (len);
	else
		return (-1);
}

char			*space_lex(void)
{
	int		len;
	int		padding;

	len = 0;
	padding = 0;
	while (g_cursor[g_pos])
	{
		if (is_delim(g_cursor + g_pos) == 0)
		{
			while (is_delim(g_cursor + g_pos) == 0)
			{
				g_pos++;
				padding++;
			}
			break ;
		}
		else
			len++;
		g_pos++;
	}
	if (len > 0)
		return (new_lexeme(g_cursor + (g_pos - len - padding), len));
	return (NULL);
}

char			*lexer(char *expansion)
{
	char	*lexeme;
	int		quote_len;
	int		exp_pos;

	while (g_cursor[g_pos])
	{
		quote_len = quote_lex();
		if (quote_len > 0)
			return (new_lexeme(g_cursor + g_pos - 1 - quote_len, quote_len));
		else if (quote_len == -1)
			return (NULL);
		lexeme = space_lex();
		exp_pos = -1;
		if (lexeme)
		{
			while (lexeme[++exp_pos])
			{
				if (lexeme[exp_pos] == '~')
				{
					lexeme = expand(lexeme, expansion, exp_pos);
					exp_pos = -1;
				}
			}
			return (lexeme);
		}
		free(lexeme);
	}
	return (NULL);
}

t_token_list	*parser(t_shell *shell, char *str)
{
	char			*lexeme;
	int				pos;
	t_token_list	*token_list;

	global_init(str, 0);
	token_list = new_token_list();
	pos = -1;
	while (g_cursor[g_pos])
	{
		if ((lexeme = lexer(environ_get_value(shell->environ,
			environ_search(shell->environ, "HOME", 4)))))
		{
				token_list = token_list_push(token_list, generate_token(lexeme, ++pos));
		}
		else
		{
			token_list_destroy(token_list);
			return (NULL);
		}
	}
	return (token_list);
}

void			global_init(char *str, int pos)
{
	g_cursor = str;
	g_pos = pos;
}

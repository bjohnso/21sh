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
	if (*g_cursor == '"')
	{
		if (g_pos > 0)
			if (*(g_cursor - 1) == '\\')
				return (len);
		quote_count++;
		g_cursor += ++g_pos;
		while (*g_cursor)
		{
			if (*g_cursor == '"')
				if (*(g_cursor - 1) != '\\')
					return (len);
			len++;
			g_cursor += ++g_pos;
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
	while (*g_cursor)
	{
		if (is_delim(g_cursor) == 0)
		{
			while (is_delim(g_cursor) == 0)
			{
				g_cursor += ++g_pos;
				padding++;
			}
			break ;
		}
		else
			len++;
		g_cursor += ++g_pos;
	}
	if (len > 0)
		return (new_lexeme(g_cursor - len - padding, len));
	return (NULL);
}

char			*lexer(char *expansion)
{
	char	*lexeme;
	int		quote_len;
	int		exp_pos;

	while (*g_cursor)
	{
		quote_len = quote_lex();
		if (quote_len > 0)
			return (new_lexeme(g_cursor + 1, quote_len));
		else if (quote_len == -1)
			return (NULL);
		lexeme = space_lex();
		exp_pos = 0;
		while (*lexeme)
		{
			if (*lexeme == '~')
			{
				lexeme = expand(lexeme - exp_pos, expansion, exp_pos);
				exp_pos = 0;
			}
			lexeme += ++exp_pos;
		}
		return (lexeme - exp_pos);
	}
	return (NULL);
}

t_token_list	*parser(t_shell *shell, char *str)
{
	char			*lexeme;
	int				pos;
	t_token_list	*token_list;
	t_token			*temp;

	g_cursor = str;
	token_list = new_token_list();
	pos = -1;
	while (*g_cursor)
	{
		if ((lexeme = lexer(environ_get_value(shell->environ,
			environ_search(shell->environ, "HOME", 4)))))
		{
			temp = generate_token(lexeme, ++pos);
			if (!temp)
			{
				free(temp);
				break ;
			}
			token_list_push(token_list, temp);
		}
	}
	return (token_list);
}

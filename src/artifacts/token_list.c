/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:16 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 14:24:55 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

/*
**Constructors
*/

t_token_list		*new_token_list(void)
{
	t_token_list	*token_list;

	token_list = (t_token_list *)malloc(sizeof(t_token_list));
	token_list->tokens = NULL;
	token_list->size = 0;
	return (token_list);
}

/*
**Mutators
*/

t_token_list		*token_list_push(t_token_list *token_list, t_token *token)
{
	t_token		*tokens;
	size_t		c;

	tokens = (t_token *)ft_memalloc(sizeof(t_token) * (token_list->size + 1));
	c = -1;
	while (++c < token_list->size)
		tokens[c] = token_list->tokens[c];
	tokens[c] = *token;
	token_destroy(token);
	tokens_destroy(token_list->tokens, token_list->size);
	token_list->size++;
	token_list->tokens = tokens;
	return token_list;
}

void				tokens_destroy(t_token *tokens, size_t size)
{
	size_t		c;

	c = -1;
	while(++c < size)
		token_destroy(tokens + c);
	free(tokens);
}

void				token_list_destroy(t_token_list *token_list)
{
	size_t		counter;

	counter = -1;
	while (++counter < token_list->size)
	{
		if (token_list->tokens + counter)
			token_destroy(token_list->tokens + counter);
	}
	free(token_list);
	token_list = NULL;
}

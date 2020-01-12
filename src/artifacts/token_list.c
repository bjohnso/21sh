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
	token_list->tokens = (t_token *)malloc(sizeof(t_token));
	token_list->size = 0;
	return (token_list);
}

/*
**Mutators
*/

void				token_list_push(t_token_list *token_list, t_token *token)
{
	size_t		counter;
	t_token		*tokens;

	tokens = (t_token *)malloc(sizeof(t_token) * (token_list->size + 1));
	counter = -1;
	while (++counter < token_list->size)
	{
		tokens[counter] = token_list->tokens[counter];
	}
	tokens[token_list->size] = *token;
	free(token_list->tokens);
	token_list->tokens = tokens;
	token_list->size += 1;
}

void				token_list_destroy(t_token_list *token_list)
{
	size_t		counter;

	counter = -1;
	while (++counter < token_list->size)
	{
		free(token_list->tokens[counter].lexeme);
	}
	free(token_list->tokens);
	free(token_list);
	token_list = NULL;
}

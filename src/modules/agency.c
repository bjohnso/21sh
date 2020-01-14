/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agency.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:38 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/14 14:14:54 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

t_agent			*compute_execute(t_shell *shell, t_token_list *t_list)
{
	t_agent		*a;
	size_t		c;
	size_t		c_alt;

	if ((a = new_agent(shell, t_list->tokens[0])))
	{
		a = agent_opt_push(a, '-');
		c = 0;
		while (++c < t_list->size)
		{
			if (ft_strcmp(t_list->tokens[c]->type, "option") == 0)
			{
				c_alt = 0;
				while (++c_alt < ft_strlen(t_list->tokens[c]->lexeme) + 1)
					if (t_list->tokens[c]->lexeme[c_alt] != '-')
						a = agent_opt_push(a, t_list->tokens[c]->lexeme[c_alt]);
			}
			else if (ft_strcmp(t_list->tokens[c]->type, "file") == 0)
				a = agent_files_push(a, t_list->tokens[c]->lexeme);
			else
				break ;
		}
		a = agent_generate_exec_args(a);
	}
	return (a);
}

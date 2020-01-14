/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:48 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/14 16:11:25 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

void		print_array(char **str, char *tag)
{
	size_t		c;

	c = -1;
	while (++c < ft_sstrlen(str))
		ft_printf("%s : %s\n", tag, str[c]);
}

void		print_exe_report(t_shell *sh, t_token_list *t_list, t_agent *agent)
{
	size_t		c;

	c = -1;
	ft_printf("Current Directory : %s\n", sh->dir[0]);
	while (++c < t_list->size)
		ft_printf("Lexeme : %s | Type : %s\n",
			t_list->tokens[c]->lexeme, t_list->tokens[c]->type);
	ft_printf("Agent Alias : %s\n", agent->alias);
	ft_printf("Agent Target : %s\n", agent->target);
	if (agent->options)
		ft_printf("Agent Options : %s\n", agent->options);
	if (agent->files)
		print_array(agent->files, "Agent Payload");
	if (agent->exec_args)
		print_array(agent->exec_args, "Execution Args");
	ft_printf("Agent Command Status : %s\n",
		agent->command_status ? "true" : "false");
	ft_printf("Agent Execution Status : %s\n",
		agent->execution_status ? "true" : "false");
}

t_shell		*mini_buff(t_shell *s, t_buffer *b, t_token_list *t, t_agent *a)
{
	ft_printf("%s $> ", s->alias);
	if ((b = input_reader()))
	{
		s = mini_shell(s, b, t, a);
		buffer_destroy(b);
	}
	return (s);
}

t_shell		*mini_shell(t_shell *s, t_buffer *b, t_token_list *t, t_agent *a)
{
	if ((t = parser(s, b->str)))
	{
		if ((a = compute_execute(s, t)))
		{
			if (a->command_status)
			{
				if (execute(s, a) == -1)
					ft_printf("Command Failed...\n");
			}
			else
				ft_printf("%s is a directory\n", a->alias);
			if (s->debug == true)
				print_exe_report(s, t, a);
			agent_destroy(a);
		}
		else
			ft_printf("Command is not valid...\n");
		token_list_destroy(t);
	}
	else
		ft_printf("Input is not valid...\n");
	return (s);
}

int			main(int argc, char **argv)
{
	t_shell				*shell;
	t_buffer			*buffer;
	t_token_list		*token_list;
	t_agent				*agent;

	if (argc > 0 && argv[0])
	{
		if ((shell = new_shell(argv[0])))
		{
			buffer = NULL;
			token_list = NULL;
			agent = NULL;
			if (argv[1] && ft_strcmp(argv[1], "-e") == 0)
				shell->debug = true;
			while (!shell->exit)
				shell = mini_buff(shell, buffer, token_list, agent);
			shell_destroy(shell);
			exit(0);
		}
	}
}

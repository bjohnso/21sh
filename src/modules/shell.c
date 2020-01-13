/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:48 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 14:26:22 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

int     main(int argc, char **argv)
{
	t_shell				*shell;
	t_buffer			*buffer;
	t_token_list		*token_list;
    t_agent				*approved_agent;

	if (argc > 0 && argv[0])
	{
		if ((shell = new_shell()))
		{
			while (!shell->exit)
			{
				ft_printf("%s $> ", argv[0]);
				if ((buffer = input_reader()))
				{
					if ((token_list = parser(shell, buffer->str)))
					{
						if ((approved_agent = compute_execute(shell, token_list)))
						{
							if (approved_agent->command_status)
							{
								if (execute(shell, approved_agent) == -1)
									ft_printf("Execution Error... Executor Manager Failed to Dispatch...\n");
							}
							else
								ft_printf("%s is a directory\n", approved_agent->alias);
							if (argv[1] && ft_strcmp(argv[1], "-e") == 0)
							{
								ft_printf("%s","\n\n----------EXECUTION REPORT----------\n\n");
								ft_printf("Current Directory : %s\n", shell->dir[0]);
								for (size_t i = 0; i < token_list->size; i++)
									ft_printf("Lexeme : %s | Type : %s\n", token_list->tokens[i].lexeme, token_list->tokens[i].type);
								ft_printf("Agent Alias : %s\n", approved_agent->alias);
								ft_printf("Agent Target : %s\n", approved_agent->target);
								if(approved_agent->options)
									ft_printf("Agent Options : %s\n", approved_agent->options);
								if (approved_agent->files)
								{
									for (size_t i = 0; i < ft_sstrlen(approved_agent->files); i++)
										ft_printf("Agent Payload : %s\n", approved_agent->files[i]);
								}
								if (approved_agent->exec_args)
								{
									for (size_t i = 0; i < ft_sstrlen(approved_agent->exec_args); i++)
										ft_printf("Execution Arguments : %s\n", approved_agent->exec_args[i]);
								}
								ft_printf("Agent Command Status : %s\n", approved_agent->command_status  ? "true" : "false");
								ft_printf("Agent Execution Status : %s\n", approved_agent->execution_status ? "true" : "false");
							}
							agent_destroy(approved_agent);
						}
						else
						{
							if (argv[1] && ft_strcmp(argv[1], "-e") == 0)
							{
								for (size_t i = 0; i < token_list->size; i++)
								{
									ft_printf("Lexeme : %s | Type : %s\n", token_list->tokens[i].lexeme, token_list->tokens[i].type);
								}
							}
							ft_printf("Error... Agenency Failed to Dispatch an Agent\n");
						}
						token_list_destroy(token_list);
					}
					else
						ft_printf("Syntax Error\n");
                	if (argv[1] && ft_strcmp(argv[1], "-e") == 0)
                		ft_printf("%s", "\n");
					buffer_destroy(buffer);
				}
			}
			shell_destroy(shell);
			exit(0);
		}
	}
}

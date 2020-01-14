/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:46 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/14 15:50:35 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

void			mini_echo(t_shell *shell, t_agent *agent)
{
	size_t	counter;
	int		pos;

	counter = -1;
	if (agent->files)
	{
		while (++counter < ft_sstrlen(agent->files))
		{
			if (agent->files[counter][0] == '$')
			{
				pos = environ_search(shell->environ, agent->files[counter]
					+ 1, ft_strlen(agent->files[counter]) - 1);
				if (pos != -1)
					ft_printf("%s", environ_get_value(shell->environ, pos));
			}
			else
				ft_printf("%s", agent->files[counter]);
			if (counter + 1 < ft_sstrlen(agent->files))
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}

int				mini_cd(t_shell *shell, t_agent *agent)
{
	if (agent->files)
	{
		if (ft_sstrlen(agent->files) > 1)
			return (-1);
		if (ft_strcmp(shell->dir[0], agent->files[0]))
		{
			if (ft_strcmp(agent->files[0], "-") == 0)
				return (chdir(shell->dir[1]));
			return (chdir(agent->files[0]));
		}
		else
		{
			ft_printf("%s\n", "Already at the specified directory");
			return (1);
		}
	}
	else
		return (chdir(environ_get_value(shell->environ,
			environ_search(shell->environ, "HOME", 4))));
}

void			mini_env(t_shell *shell)
{
	size_t		counter;

	counter = -1;
	while (++counter < ft_sstrlen(shell->environ))
		ft_printf("%s\n", shell->environ[counter]);
}

int				mini_setenv(t_shell *shell, t_agent *agent)
{
	size_t		c;
	size_t		c_alt;
	int			split;

	c = -1;
	c_alt = -1;
	if (agent->files)
	{
		while (++c < ft_sstrlen(agent->files))
		{
			split = 0;
			while (++c_alt < ft_strlen(agent->files[c]))
			{
				if (agent->files[c][c_alt] == '=')
				{
					split = c_alt;
					break ;
				}
			}
			if (split != 0)
				env_add_or_replace(shell, agent->files[c], split);
		}
	}
	return (1);
}

int				mini_unsetenv(t_shell *shell, t_agent *agent)
{
	size_t		c;
	int			pos;

	c = -1;
	if (agent->files)
	{
		while (++c < ft_sstrlen(agent->files))
		{
			if (agent->files[c][0] == '$')
			{
				if ((pos = environ_search(shell->environ, agent->files[c]
					+ 1, ft_strlen(agent->files[c]) - 1)) != -1)
					environ_delete(shell, pos);
			}
			else
			{
				if ((pos = environ_search(shell->environ, agent->files[c]
					, ft_strlen(agent->files[c]))) != -1)
					environ_delete(shell, pos);
			}
		}
	}
	return (1);
}

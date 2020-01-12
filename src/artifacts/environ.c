/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:51:47 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 14:29:11 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

char			**environ_init(char **env)
{
	size_t		env_len;
	size_t		counter;
	char		**temp_env;

	env_len = ft_sstrlen(env);
	counter = -1;
	temp_env = (char **)malloc(sizeof(char *) * (env_len + 1));
	while (++counter < env_len)
	{
		temp_env[counter] = environ_pair_clone(env[counter]);
	}
	temp_env[env_len] = NULL;
	return (temp_env);
}

void			environ_push(t_shell *shell, char *pair)
{
	size_t		env_len;
	size_t		counter;
	char		**temp_env;

	env_len = ft_sstrlen(shell->environ);
	counter = -1;
	temp_env = (char **)malloc(sizeof(char *) * (env_len + 2));
	while (++counter < env_len)
	{
		temp_env[counter] = shell->environ[counter];
	}
	temp_env[env_len] = environ_pair_clone(pair);
	temp_env[env_len + 1] = NULL;
	free(shell->environ);
	shell->environ = temp_env;
}

void			environ_replace(t_shell *shell, char *pair, int position)
{
	free(shell->environ[position]);
	shell->environ[position] = environ_pair_clone(pair);
}

void			environ_delete(t_shell *shell, int position)
{
	size_t		env_len;
	size_t		counter;
	char		**temp_env;

	env_len = ft_sstrlen(shell->environ);
	counter = -1;
	temp_env = (char **)malloc(sizeof(char *) * env_len);
	while (++counter < env_len - 1)
	{
		if (counter >= (size_t)position)
			temp_env[counter] = shell->environ[counter + 1];
		else
			temp_env[counter] = shell->environ[counter];
	}
	temp_env[env_len - 1] = NULL;
	free(shell->environ[position]);
	free(shell->environ);
	shell->environ = temp_env;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:37:16 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 14:27:49 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

/*
**Constructor
*/

t_shell			*new_shell(void)
{
	extern char		**environ;
	t_shell			*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->dir = (char**)malloc(sizeof(char *) * 3);
	shell->dir[2] = NULL;
	shell->dir[0] = getcwd(NULL, 0);
	shell->exit = false;
	shell->environ = environ_init(environ);
	return (shell);
}

/*
**Directory
*/

char			*file_search(char *dir, char *alias)
{
	char	*file;

	file = NULL;
	build_file_path(file, dir, alias);
	if (file)
	{
		if (access(file, F_OK) == 0)
			return (file);
	}
	free(file);
	return (NULL);
}

void			build_file_path(char *file, char *dir, char *alias)
{
	size_t		len;
	size_t		counter;

	len = ft_strlen(dir) + ft_strlen(alias);
	counter = -1;
	if (dir[ft_strlen(dir) - 1] != '/')
		len++;
	file = (char *)malloc(sizeof(char) * (len + 1));
	while (++counter <= len)
	{
		if (counter < ft_strlen(dir))
			file[counter] = dir[counter];
		else
		{
			if (dir[ft_strlen(dir) - 1] != '/' && counter == ft_strlen(dir))
				file[counter] = '/';
			else
			{
				if (dir[ft_strlen(dir) - 1] != '/')
					file[counter] = alias[counter - ft_strlen(dir) - 1];
				else
					file[counter] = alias[counter - ft_strlen(dir)];
			}
		}
	}
}

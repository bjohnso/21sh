/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:46 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:55:47 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

void     mini_echo(t_shell *shell, t_agent *agent){

    if (agent->files){
        for (size_t i = 0; i < ft_sstrlen(agent->files); i++){
            if (agent->files[i][0] == '$'){
                int     pos = environ_search(shell->environ, agent->files[i] + 1, ft_strlen(agent->files[i]) - 1);
                if (pos != -1){
                    ft_printf("%s", environ_get_value(shell->environ, pos));
                }
            }
            else
                ft_printf("%s", agent->files[i]);
            if (i + 1 < ft_sstrlen(agent->files))
                ft_printf("%s"," ");
        }
        ft_printf("%s","\n");
    } else {
        ft_printf("%s"," \n");
    }
}

int     mini_cd(t_shell *shell, t_agent *agent){

    if (agent->files){
        if (ft_sstrlen(agent->files) > 1){
            return -1;
        }
        if (ft_strcmp(shell->dir[0], agent->files[0])){
            if (ft_strcmp(agent->files[0], "-") == 0){
                return chdir(shell->dir[1]);
            }
            return chdir(agent->files[0]);
        } else {
            ft_printf("Already at the specified path...");
            return -1;
        }
    } else {
        //TODO: USE ENVIRON HOME DIR
        return chdir(environ_get_value(shell->environ, environ_search(shell->environ, "HOME", 4)));
    }
}

void    mini_env(t_shell *shell){
    for (size_t i = 0; i < ft_sstrlen(shell->environ); i++){
        ft_printf("%s\n", shell->environ[i]);
    }
}

int    mini_setenv(t_shell *shell, t_agent *agent){
    if (agent->files){
        for (size_t i = 0; i < ft_sstrlen(agent->files); i++){
            int split = 0;
            for (size_t j = 0; j < ft_strlen(agent->files[i]); j++){
                if (agent->files[i][j] == '='){
                    split = j;
                    break ;
                }
            }
            //IF ARG HAS AN EQUALS AND THE 
            if (split !=0){
                int pos;
                if ((pos = environ_search(shell->environ, agent->files[i], split)) != -1){
                    environ_replace(shell, agent->files[i], pos);
                } else {
                    environ_push(shell, agent->files[i]);
                }
            } else {
                return -1;
            }
        }
    }
    return 1;
}

int    mini_unsetenv(t_shell *shell, t_agent *agent){
    if (agent->files){
        for (size_t i = 0; i < ft_sstrlen(agent->files); i++){
            int pos;
            if (agent->files[i][0] == '$'){
                if ((pos = environ_search(shell->environ, agent->files[i] + 1, ft_strlen(agent->files[i])- 1)) != -1){
                    environ_delete(shell, pos);
                } else {
                    return -1;
                }
            } else {
                if ((pos = environ_search(shell->environ, agent->files[i], ft_strlen(agent->files[i]))) != -1){
                    environ_delete(shell, pos);
                } else {
                    return -1;
                }
            }
        }
    }
    return 1;
}
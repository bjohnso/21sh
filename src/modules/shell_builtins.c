#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

void     mini_echo(t_agent *agent){

    if (agent->files){
        for (size_t i = 0; i < ft_sstrlen(agent->files); i++){
            ft_printf(agent->files[i]);
            if (i + 1 < ft_sstrlen(agent->files))
                ft_printf(" ");
        }
        ft_printf("\n");
    } else {
        ft_printf(" \n");
    }
}

int     mini_cd(t_shell *shell, t_agent *agent){

    if (agent->files){
        if (ft_strcmp(shell->dir, agent->files[0])){
            return chdir(agent->files[0]);
        } else {
            ft_printf("Already at the specified path...");
            return -1;
        }
    } else {
        return chdir(shell->home_dir);
    }
}

void    mini_env(char **env){
    for (size_t i = 0; i < ft_sstrlen(env); i++){
        ft_printf("%s\n", env[i]);
    }
}
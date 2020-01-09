#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

int         execute(t_shell *shell, t_agent *agent){

    pid_t   pid, wpid;
    int     status = 0;

    if (agent->target[0] == '/'){
        pid = fork();
        if (pid == 0){
            execve(agent->target, agent->exec_args, shell->environ);
            status = -1;
            exit(0);
        } else {
            wpid = wait(0);
            if (status != -1)
                agent->execution_status = true;
            return status;
        }
    } else {
        if (ft_strcmp(agent->alias, "echo") == 0){
            mini_echo(agent);
        }
        else if (ft_strcmp(agent->alias, "cd") == 0){
            status =  mini_cd(shell, agent);
            if (status != -1){
                agent->execution_status = true;
                free(shell->dir);
                shell->dir = getcwd(NULL, 0);
            }
        }
        else if (ft_strcmp(agent->alias, "env") == 0){
            mini_env(shell);
            agent->execution_status = true;
        } 
        else if (ft_strcmp(agent->alias, "setenv") == 0){
            if (mini_setenv(shell, agent) != -1){
                agent->execution_status = true;
            }
        }
        else if (ft_strcmp(agent->alias, "unsetenv") == 0){
            if (mini_unsetenv(shell, agent) != -1){
                agent->execution_status = true;
            }
        }
        return status;
    }
    return -1;
}
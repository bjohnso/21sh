#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

extern char **environ;

int         execute(t_agent *agent){

    pid_t   pid, wpid;
    int     status = 0;

    pid = fork();
    
    if (pid == 0){
        agent->execution_status = true;
        execve(agent->target, agent->exec_args, environ);
        status = -1;
        exit(0);
    } else {
        wpid = wait(0);
        return status;
    }
}
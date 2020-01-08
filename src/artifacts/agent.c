#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h" 

static char   *aliases[6] = {
    "ls",
    "cat",
    "cd",
    "exit",
    "mv",
    "echo"
};

static char   *targets[6] = {
    "/bin/ls",
    "/bin/cat",
    "/bin/cd",
    "/bin/exit",
    "/bin/mv",
    "/bin/echo"
};

t_agent             *new_agent(char *alias){
    t_agent     *agent = (t_agent *)malloc(sizeof(t_agent));

    agent->alias = alias;
    if ((agent->target = agent_map_target(agent->alias)))
    {
        agent->execution_status = false;
    }
    else {
        free(agent);
        return NULL;
    }

    agent->options = NULL;
    agent->files = NULL;

    return agent;
}

char          *agent_map_target(char *alias){
    for (size_t i = 0; i < ft_sstrlen((char **)aliases); i++){
        if (ft_strcmp(aliases[i], alias) == 0){
            return targets[i];
        }
    }

    return NULL;
}

void                agent_options_push(t_agent *agent, char option){
    if (agent->options == NULL){
        agent->options = (char *)malloc(sizeof(char) + 1);

        agent->options[0] = option;
        agent->options[1] = '\0';
    } else {
        size_t  len = ft_strlen(agent->options);
        char    *temp = (char *)malloc(sizeof(char) * (len + 2));

        for (size_t i = 0; i < len; i++){
            temp[i] = agent->options[i];
        }

        temp[len] = option;
        temp[len + 1] = '\0';

        free(agent->options);

        agent->options = temp;
    }
}

void                agent_files_push(t_agent *agent, char *file){
    if (agent->files == NULL){
        agent->files = (char **)malloc(sizeof(char) + 1);

        agent->files[0] = file;
        agent->files[1] = NULL;
    } else {
        size_t  len = ft_sstrlen(agent->files);
        char    **temp = (char **)malloc(sizeof(char *) * (len + 2));

        for (size_t i = 0; i < len; i++){
            temp[i] = agent->files[i];
        }

        temp[len] = file;
        temp[len + 1] = NULL;

        free(agent->files);

        agent->files = temp;
    }
}

void                agent_generate_exec_args(t_agent *agent){

    //POSIBLY ADD '-' to options
    char        **exec_args;
    size_t      len;
    size_t      i;

    if (agent->files)
        len = ft_sstrlen(agent->files);
    else
        len = 0;
    if (agent->options)
         i = 2;
    else
        i = 1; 

    len += i;
    exec_args = (char **)malloc(sizeof(char *) * (len + 1));

    exec_args[0] = agent->alias;

    if (i == 2)
        exec_args[1] = agent->options;

    for(size_t j = i; j < len; j++){
        exec_args[j] = agent->files[j - i];
    }

    exec_args[len] = NULL;
    agent->exec_args = exec_args;
}

void                agent_clone(t_agent *clone, t_agent *agent){
    clone->alias = agent->alias;
    clone->target = agent->target;
    clone->options = agent->options;
    clone->files = agent->files;
    clone->execution_status = agent->execution_status;
}
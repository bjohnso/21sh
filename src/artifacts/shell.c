#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

extern char     **environ;

//Constructor

t_shell     *new_shell(){
    t_shell     *shell;

    shell = (t_shell *)malloc(sizeof(t_shell));
    shell->home_dir = getenv("HOME");
    shell->dir = getcwd(NULL, 0);
    shell->exit = false;
    shell->environ = environ_init(environ);

    return shell;
}

//Environ

char            **environ_init(char **env){
    size_t  env_len = ft_sstrlen(env);
    char    **temp_env = (char **)malloc(sizeof(char *) * (env_len + 1));

    for (size_t i = 0; i < env_len; i++){
        temp_env[i] = environ_pair_clone(env[i]);
    }

    temp_env[env_len] = NULL;
    return temp_env;
}

void            environ_push(t_shell *shell, char *pair){
    
    size_t  env_len = ft_sstrlen(shell->environ);
    char    **temp_env = (char **)malloc(sizeof(char *) * (env_len + 2));

    for (size_t i = 0; i < env_len; i++){
        temp_env[i] = shell->environ[i];
    }

    temp_env[env_len] = environ_pair_clone(pair);
    temp_env[env_len + 1] = NULL;

    free(shell->environ);

    shell->environ = temp_env;
}

int           environ_search(char **env, char *pair, int split){
    for (size_t i = 0; i < ft_sstrlen(env); i++){
        if (ft_strncmp(env[i], pair, split) == 0){
            return i;
        }
    }
    return -1;
}

void            environ_replace(t_shell *shell, char *pair, int position){
    free(shell->environ[position]);
    shell->environ[position] = environ_pair_clone(pair);
}

void            environ_delete(t_shell *shell, int position){
    size_t  env_len = ft_sstrlen(shell->environ);
    char    **temp_env = (char **)malloc(sizeof(char *) * env_len);

    for (size_t i = 0; i < env_len - 1; i++){
        if (i >= (size_t)position){
            temp_env[i] = shell->environ[i + 1];
        } else {
            temp_env[i] = shell->environ[i];
        }
    }
    temp_env[env_len - 1] = NULL;

    free(shell->environ[position]);
    free(shell->environ);
    shell->environ = temp_env;
}

char            *environ_pair_clone(char *original){
    size_t  len = ft_strlen(original);
    char    *clone = (char *)malloc(sizeof(char) * (ft_strlen(original) + 1));

    for (size_t i = 0; i < len; i++){
        clone[i] = original[i];
    }

    clone[len] = '\0';
    return clone;
}
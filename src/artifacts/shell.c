#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

//Constructor

t_shell     *new_shell(){
    t_shell     *shell;

    shell = (t_shell *)malloc(sizeof(t_shell));
    shell->home_dir = getenv("HOME");
    shell->dir = getcwd(NULL, 0);
    shell->exit = false;

    return shell;
}
# ifndef FT_SH_H
# define FT_SH_H

#include "libft.h"

typedef struct      s_shell
{
    bool    quit;
    char    **argv;
    char    **env;
    char    **localenv;
    char    *prompt;
    int     argc;
}                   t_shell;

typedef struct      s_tokenlist
{
    char                type[3];
    int                 len;
    struct s_tokenlist  *next;
    struct s_tokenlist  *last;
    void                *content;
}                       t_tokenlist;

#endif
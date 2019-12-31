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

typedef struct      s_token
{
    char            *lexeme;
    char            *type;
    int             pos;
}                   t_token;

typedef struct      s_token_list
{
    t_token     **token_list;
    int         size;
}                   t_token_list;

#endif
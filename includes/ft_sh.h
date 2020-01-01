# ifndef FT_SH_H
# define FT_SH_H

#include "libft.h"

typedef struct      s_shell
{
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
    t_token     *tokens[10];
    int         size;
}                   t_token_list;

//Parser

char                *lexer(char *str);
t_token_list        *parser(char    *str);
t_token             *generate_token(char  *lexeme, int pos);
t_token             *new_token(char  *lexeme, int pos, char *type);

#endif
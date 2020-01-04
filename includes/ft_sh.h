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
    t_token         *tokens;
    int             size;
}                   t_token_list;

//Parser

char                *lexer(char *str);
t_token_list        *parser(char    *str);
t_token             *generate_token(char  *lexeme, int pos);
t_token             *new_token(char  *lexeme, int pos, char *type);
t_token_list        *new_token_list();
void                token_list_push(t_token_list *token_list, t_token *token);

#endif
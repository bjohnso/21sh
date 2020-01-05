# ifndef FT_SH_H
# define FT_SH_H

#include "libft.h"

typedef struct      s_shell
{
    bool            exit;
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

typedef struct      s_buffer
{
    char            *str;
    int             size;
}                   t_buffer;

//Shell
t_shell             *new_shell();

//Parser
char                *lexer(char *str);
t_token_list        *parser(char    *str);

//Token
t_token             *generate_token(char  *lexeme, int pos);
t_token             *new_token(char  *lexeme, int pos, char *type);
t_token_list        *new_token_list();
void                token_list_push(t_token_list *token_list, t_token *token);

//Input Reader
char                *input_reader();

//Buffer
t_buffer            *new_buffer();
void                buffer_push(t_buffer *buffer, char c);

#endif
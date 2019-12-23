#include "ft_sh.h"

static const char   *keywords[6] = {
    "ls",
    "cat",
    "cd",
    "exit",
    "mv",
    "echo"
}; 

char     *lexer(char *str){
    char    *look = *str;
    char    *lexeme;
    int     len = 0;

    while (*look){
        if (*look == ' '){
            lexeme = (char*)malloc(sizeof(char) * len);
            ft_strncpy(lexeme, str, len);
            str += len;
            len = 0;
            return lexeme;
        } else {
            len++;
        }
        look++;
    }
}

t_token         *new_token(char *lexeme, int pos){
    t_token     *token;
    
    token = (t_token *)malloc(sizeof(t_token));

    token->lexeme = lexeme;
    token->pos = pos;

    return token;
}

t_token_list    *parser(char *str){

    t_token_list    *token_list = (t_token_list *)malloc(sizeof(t_token_list));
    t_token         *token;
    char            *lexeme = (char *)malloc(sizeof(char));
    int             pos = 0;

    while(*str){
        token = new_token(lexer(str), pos);
        ft_realloc(token_list->token_list, pos, pos+1);
        token_list->token_list[pos] = token;
        pos++;
    }

    return token_list;
}
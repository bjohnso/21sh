#include "ft_sh.h"

static const char   *keywords[6] = {
    "ls",
    "cat",
    "cd",
    "exit",
    "mv",
    "echo"
}; 

t_token     *lexer(char *str){
    bool delim = false;
    char *str;
    char *lexeme;

    while (*str){
        if (ft_isalpha(*str) || ft_isdigit(*str)){
            
            //Loop through till delimit
        } else if (ft_isdigit(*str)) {
            //Loop through till delimit
        } else if (){
            //Break;
        }

        str++;
    }
}

t_token         *new_token(char *lexeme, char *type, int pos){
    t_token     *token;
    
    token = (t_token *)malloc(sizeof(t_token));

    token->lexeme = lexeme;
    token->type = type;
    token->pos = pos;

    return token;
}

t_token_list    *parser(char *str){

    t_token_list *token_list;
    t_token      *token;
    char         *lexeme = (char *)malloc(sizeof(char));

    while((token = lexer)){
        
    }

}
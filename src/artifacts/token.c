#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h" 

//Constructors
t_token         *new_token(char *lexeme, int pos, char *type){
    t_token     *token;
    
    token = (t_token *)malloc(sizeof(t_token));
    token->pos = pos;
    token->lexeme = lexeme;
    token->type = type;

    return token;
}

//Auxillary Functions
t_token         *generate_token(char  *lexeme, int pos){

    

    //Check for Command
    if (pos == 0){
        if (lexeme[0] != '/'){
            size_t len = ft_strlen(lexeme);
            for (size_t i = 1; i < len; i++){
                if(lexeme[i] == '/'){
                    return new_token(lexeme, pos, "file");
                }
            }
        }
        return new_token(lexeme, pos, "command");
    }
    else {
        if (*lexeme == '-'){
            return new_token(lexeme, pos, "option");
        } else {
            return new_token(lexeme, pos, "file");
        }
    }
}

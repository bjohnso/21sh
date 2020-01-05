#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h" 

//Globals
static const char   *keywords[6] = {
    "ls",
    "cat",
    "cd",
    "exit",
    "mv",
    "echo"
};

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
        for (size_t i  = 0; i < 6; i++){
            if (ft_strcmp(lexeme, keywords[i]) == 0){
                return new_token(lexeme, pos, "command");
            }
        }
        return ((void *)0);
    } else {
        if (*lexeme == '-'){
            return new_token(lexeme, pos, "option");
        } else {
            return new_token(lexeme, pos, "file");
        }
    }
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

//Globals

static int input_len = 0;
static int cursor = 0;
static const char   *keywords[6] = {
    "ls",
    "cat",
    "cd",
    "exit",
    "mv",
    "echo"
};

char      *lexer(char *str){
    char    *look = str;  
    char    *lexeme = NULL;
    int     len = 0;

    look += cursor;

    while (*look){
        if (*look == ' '){
            cursor++;
            break;
        }
        else 
            len++;
        cursor++;
        look++;
    }

    if (len > 0){

        //Allocate memory for lexeme
        lexeme = (char*)malloc(sizeof(char) * len);
        lexeme[len] = '\0';
            
        //Set lookahead pointer to start of lexeme
        look -= len;

        //Copy Lexeme into return value for len characters
        ft_strncpy(lexeme, look, len);

        //Reset len to zero
        len = 0;

        return lexeme;
    }

    return NULL;
}

t_token_list    *parser(char *str){
    //Set Global Input length
    input_len = ft_strlen(str);

    char            *lexeme;
    t_token_list    *token_list = new_token_list();
    int             pos = 0;

    //Watch out for memeory leaks!!!
    while((lexeme = lexer(str))){
        t_token     *temp = generate_token(lexeme, pos);
        ft_printf("New Lexeme : %s\n", lexeme);
        if (!temp){
            free(temp);
            return NULL;
        }

        token_list_push(token_list, temp);

        ft_printf("New Token : %s\n", token_list->tokens[pos].lexeme);
        pos++;
    }
    
    return token_list;
}

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

//Constructors
t_token         *new_token(char *lexeme, int pos, char *type){
    t_token     *token;
    
    token = (t_token *)malloc(sizeof(t_token));
    token->pos = pos;
    token->lexeme = lexeme;
    token->type = type;

    return token;
}

t_token_list    *new_token_list(){
    t_token_list    *token_list;

    token_list = (t_token_list *)malloc(sizeof(t_token_list));
    token_list->tokens = (t_token *)malloc(sizeof(t_token));
    token_list->size = 0;

    return token_list;
}

//Mutators
void            token_list_push(t_token_list *token_list, t_token *token){
    
    t_token     *new_token_array =  (t_token *)malloc(sizeof(t_token) * (token_list->size + 1));

    for (int i = 0;  i <= token_list->size; i++){
        new_token_array[i] = token_list->tokens[i];
    }

    new_token_array[token_list->size] = *token;

    free(token_list->tokens);

    token_list->tokens = new_token_array;
    token_list->size += 1;
}
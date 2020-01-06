#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

//Globals

static int input_len = 0;
static int cursor = 0;

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
    cursor = 0;
    t_agent         *agent;
    char            *lexeme;
    t_token_list    *token_list = new_token_list();
    int             pos = 0;

    //Watch out for memeory leaks!!!
    while((lexeme = lexer(str))){
        t_token     *temp = generate_token(lexeme, pos);
        if (!temp){
            free(temp);
            return NULL;
        }

        if (pos == 0 && (agent = new_agent(temp->lexeme))){
            token_list->agent = agent;
        }

        token_list_push(token_list, temp);
        pos++;
    }

    return token_list;
}
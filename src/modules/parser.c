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
    int     padding = 0;

    look += cursor;

    while (*look){
        if (*look == ' ' || *look == '\t'){
            while(*look == ' ' || *look == 9){
                ft_printf("TAB");
                cursor++;
                look++;
                padding++;
            }
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
        look = look - len - padding;

        //Copy Lexeme into return value for len characters
        ft_strncpy(lexeme, look, len);

        //Reset len to zero
        len = 0;

        ft_printf("LEX: %s\n", lexeme);

        return lexeme;
    }

    return NULL;
}

t_token_list    *parser(t_shell *shell, char *str){
    //Set Global Input length
    input_len = ft_strlen(str);
    cursor = 0;
    t_agent         *agent;
    char            *lexeme;
    t_token_list    *token_list = new_token_list();
    int             pos = 0;

    //Watch out for memeory leaks!!!
    while(cursor < input_len){
        if ((lexeme = lexer(str))){
            t_token     *temp = generate_token(lexeme, pos);
            if (!temp){
                free(temp);
                return NULL;
            }

            if (pos == 0){
                if ((agent = new_agent(shell, temp))){
                    token_list->agent = agent;
                } else {
                    free(temp);
                    return NULL;
                }
            }

            token_list_push(token_list, temp);
            pos++;
        }
    }

    if (token_list->size > 0)
        return token_list;
    return NULL;
}
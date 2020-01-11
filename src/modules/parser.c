#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

//Globals

static int input_len = 0;
static int cursor = 0;

int         is_delim(char   *str){
    if (*str == ' ' || *str == '\t'){
        return 0;
    }
    return -1;
}

char        *new_lexeme(char *str, int len){
    char    *lexeme = (char *)malloc(sizeof(char) * (len + 1));

    lexeme[len] = '\0';
    ft_strncpy(lexeme, str, len);
    return lexeme;
}

int         quote_lex(char *str){
    int     quote_count = 0;
    int     len = 0;

    if (*str == '"'){
        if (cursor > 0){
            if (*(str - 1) == '\\'){
                return len;
            }
        }
        quote_count++;
        str++;
        cursor++;
        while (*str){
            if (*str == '"'){ 
                if (*(str - 1) != '\\'){
                    return len;
                }
            }
            len++;
            str++;
            cursor++;
        }
    }
    if (quote_count == 0)
        return len;
    else
        return -1;
}

char        *space_lex(char *str){
    int     len = 0;
    int     padding = 0;

    while (*str){
        if (is_delim(str) == 0){
            while(is_delim(str) == 0){
                cursor++;
                str++;
                padding++;
            }
            break;
        }
        else{
            len++;
        } 
        cursor++;
        str++;
    }

    if (len > 0){        
        //Set lookahead pointer to start of lexeme
        str = str - len - padding;

        //Copy Lexeme into return value for len characters
        return new_lexeme(str, len);
    }
    return NULL;
}

char        *lexer(char *str){
    char    *look = str;  

    look += cursor;

    while (*look){
        int     quote_len = quote_lex(look);
        if (quote_len > 0){
            return new_lexeme(look + 1, quote_len);
        } else if (quote_len == -1){
            return NULL;
        }
        return space_lex(look);
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
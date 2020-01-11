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

char        *lexer(char *expansion, char *str){
    char    *look = str;
    char    *lexeme;  

    look += cursor;

    while (*look){
        int     quote_len = quote_lex(look);
        if (quote_len > 0){
            return new_lexeme(look + 1, quote_len);
        } else if (quote_len == -1){
            return NULL;
        }

        lexeme = space_lex(look);
        int     pos = 0;
        while(*lexeme){
            if (*lexeme == '~'){
                lexeme = expand(lexeme - pos, expansion, pos);
                pos = 0;
            }
            pos++;
            lexeme++;
        }
        return lexeme - pos;
    }
    return NULL;
}

char        *expand(char *lexeme, char *expansion, int pos){
    size_t  len_expansion = ft_strlen(expansion);
    size_t  len_lexeme = ft_strlen(lexeme);
    size_t  len = len_lexeme - 1 + len_expansion;

    char    *expanded = (char *)malloc(sizeof(char) * len + 1);
    expanded[len] = '\0';

    for (size_t i = 0; i < len; i++){
        if (i < (size_t)pos){
            expanded[i] = lexeme[i];
        } else {
            if (i == (size_t)pos){
                for (size_t j = pos; j < len_expansion; j++){
                    expanded[j] = expansion[j - pos];
                    i = j;
                }
            } else {
                expanded[i] = lexeme[++pos];
            }
        }
    }
    free(lexeme);
    if (!expanded){
        free(expanded);
        return NULL;
    }
    return expanded;
}

t_token_list    *parser(t_shell *shell, char *str){
    //Set Global Input length
    input_len = ft_strlen(str);
    cursor = 0;
    char            *lexeme;
    t_token_list    *token_list = new_token_list();
    int             pos = 0;

    //Watch out for memeory leaks!!!
    while(cursor < input_len){
        if ((lexeme = lexer(environ_get_value(shell->environ, environ_search(shell->environ, "HOME", 4)), str))){
            t_token     *temp = generate_token(lexeme, pos);
            if (!temp){
                free(temp);
                return NULL;
            }

            token_list_push(token_list, temp);
            pos++;
        }
    }

    if (token_list->size > 0){
        return token_list;
    }
    return NULL;
}
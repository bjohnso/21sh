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
    char    *look = *str;
    char    *lexeme;
    int     len = 0;

    look += cursor;

    if (cursor >= input_len)
    {
        return NULL;
    }

    while (*look){
        if (*look == ' '){
            lexeme = (char*)malloc(sizeof(char) * len);
            ft_strncpy(lexeme, str, len);
            str += len;
            cursor++;
            return lexeme;
        } else {
            len++;
        }
        cursor++;
        look++;
    }
}

t_token_list    *parser(char *str){
    //Set Global Input length
    input_len = ft_strlen(str);

    char            *lexeme;
    t_token_list    *token_list = (t_token_list *)malloc(sizeof(t_token_list));
    int             pos = 0;

    while((lexeme = lexer(str))){
        ft_realloc(token_list->token_list, pos, pos+1);
        if (!(token_list->token_list[pos] = generate_token)){
            return NULL;
        }
        pos++;
    }

    return token_list;
}
t_token         *generate_token(char  *lexeme, int pos, char *type){

    t_token     *token;

    //Check for Command
    if (pos == 0){
        for (int i  = 0; i < ft_strlen(lexeme); i++){
            if (ft_strcmp(lexeme, keywords[i]) == 0){
                return new_token(lexeme, pos, "command");
            }
        }
        return NULL;
    } else {
        if (*lexeme == '-'){
            return new_token(lexeme, pos, "option");
        } else {
            return new_token(lexeme, pos, "file");
        }
    }
}


//Constructors

t_token         *new_token(char  *lexeme, int pos, char *type){
    t_token     *token;
    
    token = (t_token *)malloc(sizeof(t_token));
    token->pos = pos;
    token->lexeme = lexeme;
    token->type = type;

    return token;
}
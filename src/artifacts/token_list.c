#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h" 

//Constructors
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
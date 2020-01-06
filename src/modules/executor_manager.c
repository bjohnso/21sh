#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

void    compute_execute(t_agent *approved_agent, t_token_list *token_list){

    //The following comparison's first validate the approved agent master variable as NOT NULL, then checksum it's alias against the first token->lexeme in the token_list
    if (approved_agent){
        if (ft_strcmp(approved_agent->alias, token_list->tokens[0].lexeme) == 0){
            for (int i = 1; i < token_list->size; i++){
                if (ft_strcmp(token_list->tokens[i].type, "option") == 0){
                    for (size_t j = 0; j < ft_strlen(token_list->tokens[i].lexeme); j++){
                        if (token_list->tokens[i].lexeme[j] != '-'){
                            agent_options_push(approved_agent, token_list->tokens[i].lexeme[j]);
                        }
                    }
                } else if (ft_strcmp(token_list->tokens[i].type, "file") == 0){
                    agent_files_push(approved_agent, token_list->tokens[i].lexeme);
                } else{
                    break ;
                }
            }
        }
    }
}
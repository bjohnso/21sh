#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

void        compute_execute(t_token_list *token_list){
    //The following comparison's first validate the approved agent master variable as NOT NULL, then checksum it's alias against the first token->lexeme in the token_list
    if (token_list->agent){
        //First Param is a valid command
        if (token_list->agent->command_status == true){
            agent_options_push(token_list->agent, '-');
            for (int i = 1; i < token_list->size; i++){
                if (ft_strcmp(token_list->tokens[i].type, "option") == 0){
                    //CONSTRUCT STRING LITERAL AS OPTION PARAMETERS
                    for (size_t j = 1; j < ft_strlen(token_list->tokens[i].lexeme) + 1; j++){
                        if (token_list->tokens[i].lexeme[j] != '-'){
                            agent_options_push(token_list->agent, token_list->tokens[i].lexeme[j]);
                        }
                    }
                } else if (ft_strcmp(token_list->tokens[i].type, "file") == 0){
                    agent_files_push(token_list->agent, token_list->tokens[i].lexeme);
                } else{
                    break ;
                }
            }
            agent_generate_exec_args(token_list->agent);
        } 
    }
}
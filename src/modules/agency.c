#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

t_agent         *compute_execute(t_shell *shell, t_token_list *token_list){

    t_agent     *agent = NULL;

    //TODO: The following comparison's first validate the approved agent master variable as NOT NULL, then checksum it's alias against the first token->lexeme in the token_list
    if (token_list){
        //Create Agent using first token
        agent = new_agent(shell, token_list->tokens);
        if (agent){
            agent_options_push(agent, '-');
            for (int i = 1; i < token_list->size; i++){
                if (ft_strcmp(token_list->tokens[i].type, "option") == 0){
                    //CONSTRUCT STRING LITERAL AS OPTION PARAMETERS
                    for (size_t j = 1; j < ft_strlen(token_list->tokens[i].lexeme) + 1; j++){
                        if (token_list->tokens[i].lexeme[j] != '-'){
                            agent_options_push(agent, token_list->tokens[i].lexeme[j]);
                        }
                    }
                } else if (ft_strcmp(token_list->tokens[i].type, "file") == 0){
                    agent_files_push(agent, token_list->tokens[i].lexeme);
                } else{
                    break ;
                }
            }
            agent_generate_exec_args(agent);
        } 
    }

    return agent;
}
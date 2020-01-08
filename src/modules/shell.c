#include "ft_sh.h"

int     main(int argc, char **argv){

    //THE SHELL IS LAUNCHED AND THE DEBRIEFER STATION IS OPENED 

    //Shell
    t_shell         *shell = new_shell();
    t_token_list    *token_list;
    char            *user_input;

    if (argc > 0 && argv[0]){
        while (!shell->exit){
            
            ft_printf("%s $> ", argv[0]);
            //REQUEST INPUT FROM THE INPUT READER
            if ((user_input = input_reader())){
                //TODO: Allow Parser to return error codes
                //REQUEST A t_token_list * from the PARSER
                if ((token_list = parser(user_input))){
                    //REQUEST A t_agent * BE BRIEFED FOR DISPATCH BY AGENCY
                    if (token_list->agent){ 
                        
                        compute_execute(token_list->agent, token_list);

                        if (execute(token_list->agent) == -1){
                            ft_printf("Execution Error... Executor Manager Failed to Dispatch...\n");
                        }
                        
                        ft_printf("\n\n----------EXECUTION REPORT----------\n\n");

                        for (int i = 0; i < token_list->size; i++){
                            ft_printf("Lexeme : %s | Type : %s\n", token_list->tokens[i].lexeme, token_list->tokens[i].type);
                        }

                        ft_printf("Agent Alias : %s\n", token_list->agent->alias);
                        ft_printf("Agent Target : %s\n", token_list->agent->target);
                        
                        if(token_list->agent->options){
                            ft_printf("Agent Options : %s\n", token_list->agent->options);
                        }

                        if (token_list->agent->files){
                            for (size_t i = 0; i < ft_sstrlen(token_list->agent->files); i++){
                                ft_printf("Agent Payload : %s\n", token_list->agent->files[i]);
                            }
                        }

                        if (token_list->agent->exec_args){
                            for (size_t i = 0; i < ft_sstrlen(token_list->agent->exec_args); i++){
                                ft_printf("Execution Arguments : %s\n", token_list->agent->exec_args[i]);
                            }
                        }

                        ft_printf("Agent Execution Status : %s\n", token_list->agent->execution_status ? "true" : "false");
                    } else {
                        for (int i = 0; i < token_list->size; i++){
                            ft_printf("Lexeme : %s | Type : %s\n", token_list->tokens[i].lexeme, token_list->tokens[i].type);
                        }
                        ft_printf("Syntax Error... Agenency Failed to Dispatch an Agent\n");
                    }
                    token_list_destroy(token_list);
                } else {
                    ft_printf("Syntax Error\n");
                }
            }
        }
    }
}
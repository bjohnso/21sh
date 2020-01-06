#include "ft_sh.h"

int     main(int argc, char **argv){

    //Shell
    t_shell         *shell = new_shell();
    t_token_list    *token_list;
    char            *user_input;

    if (argc > 0 && argv[0]){
        while (!shell->exit){
            
            ft_printf("%s $> ", argv[0]);
            if ((user_input = input_reader())){
                //TODO: Allow Parser to return error codes
                if ((token_list = parser(user_input))){
                    for (int i = 0; i < token_list->size; i++){
                        ft_printf("Lexeme : %s | Type : %s\n", token_list->tokens[i].lexeme, token_list->tokens[i].type);
                    }
                    if (token_list->agent){ 
                        compute_execute(token_list->agent, token_list);
                        ft_printf("Agent Dispatched...\n");
                        ft_printf("Agent Alias : %s\n", token_list->agent->alias);
                        ft_printf("Agent Target : %s\n", token_list->agent->target);
                        if(token_list->agent->options){
                            ft_printf("Agent Options : -%s\n", token_list->agent->options);
                        }
                        if (token_list->agent->files){
                            for (size_t i = 0; i < ft_sstrlen(token_list->agent->files); i++){
                                ft_printf("Agent Payload : %s\n", token_list->agent->files[i]);
                            }
                        }
                        ft_printf("Agent Execution Status : %s\n", token_list->agent->execution_status ? "true" : "false");
                    } else {
                        ft_printf("Syntax Error... Agent Manager Failed to Dispatch...\n");
                    }
                    token_list_destroy(token_list);
                } else {
                    ft_printf("Syntax Error\n");
                }
            }
        }
    }
}
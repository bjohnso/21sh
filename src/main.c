#include "ft_sh.h"

int     main(int argc, char **argv){

    //Shell
    t_shell         *shell = new_shell();
    t_token_list    *token_list;
    t_agent         *approved_agent = NULL;
    char            *user_input;

    if (argc > 0 && argv[0]){
        while (!shell->exit){
            
            ft_printf("%s $> ", argv[0]);
            if ((user_input = input_reader())){
                //TODO: Allow Parser to return error codes
                if ((token_list = parser(approved_agent, user_input))){
                    for (int i = 0; i < token_list->size; i++){
                        ft_printf("Lexeme : %s | Type : %s\n", token_list->tokens[i].lexeme, token_list->tokens[i].type);
                    }
                    compute_execute(approved_agent, token_list);
                    if (approved_agent){
                        ft_printf("Agent Dispatched...\n");
                        ft_printf("Agent Alias : %s\n", approved_agent->alias);
                        ft_printf("Agent Target : %s\n", approved_agent->target);
                        ft_printf("Agent Options : -%s\n", approved_agent->options);
                        for (size_t i = 0; i < ft_sstrlen(approved_agent->files); i++){
                            ft_printf("Agent Payload : %s\n", approved_agent->files[i]);
                        }
                        ft_printf("Agent Execution Status : %s\n", approved_agent->execution_status);
                    } else {
                        ft_printf("Syntax Error... Agent Manager Failed to Dispatch...\n");
                    }
                } else {
                    ft_printf("Syntax Error\n");
                }
            }
        }
    }
}
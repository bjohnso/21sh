#include "ft_sh.h"

int     main(int argc, char **argv){
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
                } else {
                    ft_printf("Syntax Error\n");
                }
            }
        }
    }
}
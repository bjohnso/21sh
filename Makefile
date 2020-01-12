NAME		:= minishell

CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror
INCLUDES	+= -I includes -I libft/includes
LDFLAGS		+= -L libft/ -lft

LIBFT		:= libft/libft.a


MODULES		:= agency executor_manager input_reader parser_util parser shell_builtins shell
ARTIFACTS	:= agent_util agent buffer environ_util environ lexeme shell token_list token

FILES		:=	$(addprefix modules/, $(MODULES)) \
				$(addprefix artifacts/, $(ARTIFACTS))
				

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): %.o: %.c
	@$(CC) -c $(INCLUDES) $(CFLAGS) $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(INCLUDES) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
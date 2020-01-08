NAME		:= minishell

CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror
INCLUDES	+= -I includes -I libft/includes
LDFLAGS		+= -L libft/ -lft

LIBFT		:= libft/libft.a


MODULES		:= shell parser input_reader agency executor_manager shell_builtins
ARTIFACTS	:= token token_list shell buffer agent

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
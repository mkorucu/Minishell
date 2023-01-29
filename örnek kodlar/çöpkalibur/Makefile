#defining colors
RESET	=	\033[0m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RED		=	\033[31m
GRAY 	= 	\033[0;90m
MAGENTA = 	\033[0;95m
CYAN 	= 	\033[0;96m


BUILTIN = builtin/built_in.c builtin/cd.c builtin/env.c builtin/exit.c builtin/pwd.C
PARSER = parser/tokenize.c
SRCS = main.c
LIB = libft/libft.a


NAME = minishell 
OBJS =	$(SRCS:.c=.o)\
		$(PARSER:.c=.o)

CC = gcc
MFLAGS = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra -lreadline -I./libft

all: $(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft

$(NAME):
	@echo "$(GREEN)Compiling... [$(NAME)]"
	@$(CC) $(CFLAGS) $(SRCS) $(PARSER) $(MFLAGS) -o $(NAME)
	@echo "$(GREEN)Finished. [$(NAME)]"

clean:
	make fclean -C ./libft
	@rm -rf *.o

fclean: clean
	make clean -C ./libft
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
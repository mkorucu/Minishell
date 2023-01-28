# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egun <egun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 13:38:18 by egun              #+#    #+#              #
#    Updated: 2023/01/24 20:23:18 by egun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m

AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc
SRC_DIR = src
UTILS_DIR = utils
UTILS = utils/utils.a
LIBFT = libft/libft.a
NAME = minishell
USERNAME = $(shell whoami)

READLINE_LIB = -L./lib/readline/lib -lreadline
INCLUDES =-Iincludes -I$(LIBFT) -I./lib/readline/include
LIB	= ./lib/.minishell

SRC = src/main.c src/builtins.c src/ft_strtrim_all.c src/exec.c			\
	  src/fill_node.c src/get_params.c src/ft_cmdtrim.c				\
	  src/expand.c src/heredoc.c src/error.c src/env.c src/custom_cmd.c		\
	  src/get_next_line.c src/get_next_line_utils.c src/prompt.c	\
	  src/ft_cmdsubsplit.c src/signal.c src/parse_args.c src/get_cmd.c

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(LIB):
	make -C ./lib

$(NAME): $(OBJ)
	make -C libft
	make -C ./utils
	$(CC) -L/Users/$(USERNAME)/readline/lib $(INCLUDES) $(CFLAGS) $(OBJ) $(LIBFT) $(UTILS) -lreadline -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -I/Users/$(USERNAME)/include $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	make clean -C utils
	$(RM) -r $(SRC_DIR)/*.o

fclean: clean
	make fclean -C libft
	make fclean -C utils
	$(RM) -r minishell

re: fclean
	@make all

norm:
	@echo "$(BLUE)"
	norminette ./src
	@echo "$(RED)"
	norminette ./utils
	@echo "$(MAGENTA)"
	norminette ./inc
	@echo "  $(GREEN)"
	norminette ./libft
	@echo "$(DEFAULT)"

.PHONY: all clean fclean norminette create_dirs test git re

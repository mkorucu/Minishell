# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 23:42:09 by mkorucu           #+#    #+#              #
#    Updated: 2023/01/28 00:25:49 by mkorucu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories:
D_SRC	=		src/main.c	src/prompt.c	src/signal.c
D_BUILTIN	=	builtins/builtin.c	builtins/cd.c

#STATUS
SUCCESS		=	@echo "\033[32mBuild successfull !\033[0m"
REMOVE		=	@echo "\033[31mDeleted !\033[0m"

LIBFT	=	libft/libft.a
NAME	=	minishell
OBJ		=	$(D_SRC:%.c=%.o) \
			$(D_BUILTIN:%.c=%.o)

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror
READLINE	=	-lreadline
RM			=	@rm -rf



all			: $(LIB) $(NAME)

$(LIB):
	@make -C ./sources/libft/
	@echo "libft compiled"

$(NAME)		: $(OBJS)
			@echo "\n"
			$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(READLINE)
			$(SUCCESS)

%.o: %.c
			@printf "\033[0;30mGenerating minishell objects... %-33.33s\r" $@
			@${CC} ${CFLAGS} -c $< -o $@

clean	:
			$(RM) $(OBJ)
			$(REMOVE)

fclean	:	clean
			$(RM) $(NAME)
		
re		:	fclean all

run		: all
		clear
		./$(NAME)

.PHONY: all re clean fclean
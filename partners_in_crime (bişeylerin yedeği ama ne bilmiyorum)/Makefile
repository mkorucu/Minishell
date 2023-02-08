# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 23:42:09 by mkorucu           #+#    #+#              #
#    Updated: 2023/02/08 16:38:22 by bkeklik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories:
D_SRC	=		src/main.c	src/signals.c

D_BUILTIN	=	builtin/builtin.c		builtin/cd.c		builtin/echo.c			builtin/env.c		builtin/exit.c		builtin/export.c	builtin/pwd.c		builtin/unset.c

D_CMD   = cmd/cmd.c cmd/run_cmd.c

D_EF = error_free/error.c error_free/free.c

D_REDIRECT	=	redirect/heredoc.c		redirect/output.c		redirect/redirect.c

D_LISTING = listing/listing.c listing/str_listing.c

D_PROCESS = processing/dolarSign.c processing/processing.c processing/remove_quotes.c

D_REDIRECT = redirect/heredoc.c redirect/output.c redirect/redirect.c

D_UTILS = utils/get_env.c utils/get_path.c utils/set_path.c

#STATUS
SUCCESS		=	@echo "\033[32mBuild successfull !\033[0m"
REMOVE		=	@echo "\033[31mDeleted !\033[0m"

NAME	=	minishell
LIBFT	=	libft/libft.a
OBJ		=	$(D_SRC:%.c=%.o) \
			$(D_BUILTIN:%.c=%.o) \
			$(D_CMD:%.c=%.o) \
			$(D_EF:%.c=%.o) \
			$(D_REDIRECT:%.c=%.o) \
			$(D_LISTING:%.c=%.o) \
			$(D_PROCESS:%.c=%.o) \
			$(D_UTILS:%.c=%.o)

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror
READLINE	=	-lreadline
RM			=	@rm -rf

all			: $(LIB) $(NAME)

$(LIB):
	@make -C ./sources/libft/
	@echo "libft compiled"

$(NAME)		: $(OBJ)
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
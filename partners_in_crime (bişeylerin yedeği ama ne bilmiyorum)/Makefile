# COLORS
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m

# Directories:
D_SRC	=		src/main.c	src/signals.c

D_BUILTIN	=	builtins/builtin.c		builtins/cd.c		builtins/echo.c			builtins/env.c		builtins/exit.c		builtins/export.c	builtins/pwd.c		builtins/unset.c

D_CMD   = cmd/cmd.c cmd/run_cmd.c

D_EF = error_free/error.c error_free/free.c

D_LISTING = listing/listing.c listing/str_listing.c

D_PROCESS = processing/dolarSign.c processing/processing.c processing/remove_quotes.c

D_REDIRECT = redirect/heredoc.c redirect/output.c redirect/redirect.c

D_UTILS = utils/get_env.c utils/get_path.c utils/set_paths.c

#STATUS
SUCCESS		=	@echo "$(GREEN)Build successfull !$(RESET)"
REMOVE		=	@echo "$(RED)Deleted !$(RESET)"

NAME	=	minishell
LIB	=	libft/libft.a
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
	@make -C ./libft/
	@echo "libft compiled"

$(NAME)		: $(OBJ)
			@echo "\n"
			$(CC) -g $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(READLINE)
			$(SUCCESS)

%.o: %.c
			@printf "\033[0;30mGenerating minishell objects... %-33.33s\r" $@
			@${CC} -g ${CFLAGS} -c $< -o $@

clean	:
			$(RM) $(OBJ)
			$(REMOVE)

fclean	:	clean
			$(RM) $(NAME)
			@make fclean -C ./libft
		
re		:	fclean all

run		: all
		clear
		./$(NAME)

.PHONY: all re clean fclean
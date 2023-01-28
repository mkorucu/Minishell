# COLORS
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m

# READLINE KRAL Halletti

# DIRECTORY
D_CMD		=	cmd/run_cmd.c			cmd/close.c			cmd/cmd.c
D_FREE		=	free/free_token.c		free/free.c
D_ERROR		=	error/error.c
D_LEXER		=	lexer/array.c			lexer/cleaner.c		lexer/dollar.c			lexer/lexer.c		lexer/process.c
D_UTILS		=	utils/ft_atoi.c			utils/ft_itoa.c		utils/ft_split.c		utils/ft_strcmp.c	utils/ft_strjoin.c	utils/ft_strncmp.c	utils/get_env.c		utils/is_heredoc.c	utils/get_path.c		utils/is_operator.c\
				utils/is_parent.c		utils/set_env.c		utils/ft_calloc.c		utils/ft_replace.c	utils/ft_strchr.c	utils/ft_strdup.c	utils/ft_strlen.c	utils/ft_substr.c	utils/is_whitespace.c	utils/set_paths.c

D_BUILTIN	=	builtin/builtin.c		builtin/cd.c		builtin/echo.c			builtin/env.c		builtin/exit.c		builtin/export.c	builtin/pwd.c		builtin/unset.c
D_REDIRECT	=	redirect/heredoc.c		redirect/input.c	redirect/output.c		redirect/redirect.c
D_TOKENIZE	=	tokenize/parse_string.c	tokenize/tokenize.c
D_MINISHELL	=	main.c

# COMMAND
SUCCESS		=	@echo "$(GREEN)Build successfull !$(RESET)"
REMOVE		=	@echo "$(RED)Deleted !$(RESET)"


# VARIABLES
NAME		=	minishell
OBJ			=	$(D_CMD:%.c=%.o) \
				$(D_FREE:%.c=%.o) \
				$(D_ERROR:%.c=%.o) \
				$(D_LEXER:%.c=%.o) \
				$(D_UTILS:%.c=%.o) \
				$(D_BUILTIN:%.c=%.o) \
				$(D_REDIRECT:%.c=%.o) \
				$(D_TOKENIZE:%.c=%.o) \
				$(D_MINISHELL:%.c=%.o)

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror
READLINE	=	-lreadline
RM			=	@rm -rf


all: $(NAME)

$(NAME)	:	$(OBJ)
			@echo "\n"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(READLINE)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:52:01 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 16:38:40 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "colors.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/ioctl.h>

# define READ_END 0
# define WRITE_END 1
# define CHILD_PROCESS 0

enum	e_builtin_types
{
	CD = 1,
	ENV,
	PWD,
	ECHO,
	EXIT,
	UNSET,
	EXPORT
};

enum e_ctype
{
	C_PIPE = '|',
	C_INPUT = '<',
	C_OUTPUT = '>',
	DOUBLE_QUOTE = '"',
	SINGLE_QUOTE = '\'',
};

enum e_ttype
{
	PIPE = 1,
	STRING,
	HERE_DOC,
	RED_INPUT,
	RED_APPEND,
	RED_OUTPUT
};

enum	e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13
};

typedef struct s_chain
{
	char			*str;
	enum e_ttype	type;
	struct s_chain	*prev;
	struct s_chain	*next;
}	t_chain;

typedef struct s_process
{
	pid_t				pid;
	int					fd[2];
	int					heredoc_fd[2];
	char				**execute;
	char				**redirects;
	struct s_process	*prev;
	struct s_process	*next;
}	t_process;

typedef struct s_data
{
	int			ac;
	int			parent_pid;
	int			process_count;
	int			ignore;
	char		*user;
	char		**env;
	char		**paths;
	t_chain		*chain;
	t_process	*process;
	int			fail;
}		t_data;

extern t_data g_crime;

int				main(int ac, char **av, char **env);
int				operator_check(char **str);
int				listing_process(void);
int				valid_op(char c);
int				check_dollar(char *str);
int				env_len(void);
int				is_include(char *str);
int				operator_check(char **str);
int				list_arguments(t_chain **chain, t_process *process);
int				add_list(t_chain **chain, t_chain *new_chain);
int				is_builtin(char *command);
int				listing_process(void);
int				check_env(char *str);
int				contain_heredoc(t_process *process);
int				ft_isnumber_with_sign(char *arg);
int				list_arguments(t_chain **chain, t_process *process);
void			set_paths(void);
void			close_heredoc(int sig);
void			handle_sigint(int sig);
void			handle_exit(char *str);
void			string_found(char **str);
void			str_listing(char **str);
void			listing(char *input);
void			builtin_pwd(void);
void			pause_cmd(void);
void			start_cmd(void);
void			remove_env(char *data);
void			builtin_exit(char **input);
void			free_array(char **arr);
void			free_process(void);
void			free_chain(void);
void			builtin_unset(char **input);
void			start_builtin(t_process	*process);
void			push_new_str(char **trimed, char *removed);
void			run_builtin(char **execute);
void			builtin_cd(char **input);
void			string_found(char **str);
void			str_listing(char **str);
void			commit_an_offense(char **env);
void			handle_sigint(int sig);
void			handle_exit(char *str);
void			create_crime(char **av, char **env);
void			run_cmd(t_process *process);
void			close_fd_all(void);
void			cmd_error(char *str);
void			chain_err(int type);
void			route_cmd(t_process *process);
void			start_builtin(t_process	*process);
void			close_heredoc(int sig);
void			listing(char *input);
void			add_env(char *str);
void			builtin_export(char **input);
void			fill_all_heredoc(void);
void			start(char *input);
void			commit_an_offense(char **env);
void			init_process(t_process **new_process);
void			pause_cmd(void);
void			start_cmd(void);
void			builtin_env(void);
void			builtin_echo(char **input);
void			heredoc(int *fd, char *endline);
void			get_all_inputs(t_process *process);
void			set_all_outputs(t_process *process);
void			output(char *file, int mode);
void			check_dir(char *cmd);
void			add_process(t_process **list, t_process *new_process);
void			push_new_str(char **trimed, char *removed);
char			*get_str(char *str, int *i);
char			*prompt(void);
char			*get_env(char *str);
char			*get_path(char *cmd);
char			*mimi_ret_free(char *mim, char *path);
char			*parse_dollar_op(char *str);
char			*remove_quotes(char *str);
char			*remove_quotes(char *str);
char			*clean_quotes(char *str, int *curr, char type);
char			**push_array(char **arr, char *new_str);
t_chain			*new_list(char *str, enum e_ttype type);
//static char		*get_str2(char *str, int	*pos, int type);

#endif

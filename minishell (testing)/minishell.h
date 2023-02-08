/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:24:38 by btekinli          #+#    #+#             */
/*   Updated: 2023/02/08 14:14:55 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
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

# define TRUE 1
# define FALSE 0
# define DOLLAR_OP '$'
# define DOUBLE_QUOTE '"'
# define SINGLE_QUOTE '\''
# define CHILD_PROCESS 0
# define MAIN_PROCESS 1
# define REPLACE 1
# define APPEND 0

enum e_builtin_types
{
	CD = 1,
	ENV,
	PWD,
	ECHO,
	EXIT,
	UNSET,
	EXPORT
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

typedef struct s_token
{
	char			*str;
	enum e_ttype	type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

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

typedef struct s_minishell
{
	int			parent_pid;
	int			process_count;
	int			ignore;
	char		**env;
	char		**paths;
	char		*user;
	t_token		*token;
	t_process	*process;
}				t_minishell;

/* Color codes for users  */
# define DEFAULT "\001\033[0;39m\002"
# define GRAY "\001\033[1;90m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define YELLOW "\001\033[1;93m\002"
# define BLUE "\001\033[1;94m\002"
# define MAGENTA "\001\033[1;95m\002"
# define CYAN "\001\033[1;96m\002"
# define WHITE "\001\033[0;97m\002"

extern t_minishell	g_ms;

int			listing_process(void);
int			env_len(void);
int			is_parent(void);
void		start_cmd(void);
void		set_paths(void);
char		*ft_itoa(int n);
void		free_chain(void);
void		builtin_pwd(void);
void		input(char *file);
void		builtin_env(void);
char		*dollar(char *str);
void		free_process(void);
void		close_fd_all(void);
char		*get_env(char *str);
void		init_process(t_process **new_process);
void		chain_error(int type);
void		listing(char *input);
void		set_env(char **env);
char		*get_path(char *cmd);
int			is_whitespace(char c);
void		cmd_error(char *str);
void		free_array(char **arr);
void		no_file_err(char *str);
int			is_operator(char *str);
void		fill_all_heredoc(void);
int			check_dollar(char *str);
char		*remove_quotes(char *str);
int			ft_atoi(const char *str);
void		directory_err(char *str);
size_t		ft_strlen(const char *s);
void		builtin_cd(char **input);
int			is_builtin(char *command);
void		builtin_exit(char **input);
void		builtin_echo(char **input);
char		*parse_dollar_op(char *str);
char		*ft_strdup(const char *str);
void		builtin_unset(char **input);
void		run_builtin(char **execute);
void		run_cmd(t_process *process);
void		output(char *file, int mode);
void		builtin_export(char **input);
void		str_listing(char **str);
void		heredoc(int *fd, char *endline);
char		*ft_strchr(const char *s, int c);
void		run_redirects(t_process *process);
void		get_all_inputs(t_process *process);
void		set_all_outputs(t_process *process);
int			contain_heredoc(t_process *process);
char		**ft_split(char const *str, char c);
void		*ft_calloc(size_t count, size_t size);
char		**push_array(char **arr, char *new_str);
void		push_new_str(char **trimed, char *removed);
t_token		*new_list(char *str, enum e_ttype type);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_substr(char const *str, unsigned int start, size_t len);
int			add_list(t_token **chain, t_token *new_chain);
void		add_process(t_process **list, t_process *new_process);



void	close_heredoc(int sig);
void	ctrl_d(char *input);
void	handle_sigint(int sig);
#endif

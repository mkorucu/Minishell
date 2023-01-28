#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
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

enum	enum_builtin_types
{
	CD = 1,
	ENV,
	PWD,
	ECHO,
	EXIT,
	UNSET,
	EXPORT
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

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
}			t_prompt;

typedef struct s_data
{
	int		ac;
	int		parent_pid;
	int		process_count;
	char	**av;
	char	**env;
	char	**paths;
	char	*read1;
	char	**read2;
	//t_token	*token;
	t_prompt	*prompt;
    int     fail;
}		t_data;

extern t_data hack;

int		main(int ac, char **av, char **env);
void	handle_sigint(int sig);

#endif
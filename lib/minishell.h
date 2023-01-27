#ifndef MINISHELL_H
#define MINISHELL_H

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
    int     fail;
}		t_data;

extern t_data hack;

#endif
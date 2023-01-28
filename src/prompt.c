#include "../lib/minishell.h"

static void	update_output(char ***matrix, int fd)
{
	char	**aux;
	char	*temp;
	char	*line;

	aux = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strtrim(line, "\n");
		free(line);
		aux = ft_extend_matrix(aux, temp);
		free(temp);
	}
	ft_free_matrix(matrix);
	*matrix = aux;
}

void	exec_custom(char ***out, char *full, char *args, char **envp)
{
	pid_t	pid;
	int		fd[2];
	char	**matrix;

	pipe(fd);
	pid = fork();
	if (!pid)
	{
		close(fd[READ_END]);
		matrix = ft_split(args, ' ');
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		if (!access(full, F_OK))
			execve(full, matrix, envp);
		exit (1);
	}
	close(fd[WRITE_END]);
	waitpid(pid, NULL, 0);
	update_output(out, fd[READ_END]);
	close(fd[READ_END]);
}

static char	*get_user(t_prompt prompt)
{
	char	**user;

	user = NULL;
	exec_custom(&user, "/usr/bin/whoami", "whoami", prompt.envp);
	return (*user);
}

char	*get_prompt()
{
	char	*user;
	char	*prompt;
	char	*prompt2;

	user = get_user(*hack.prompt);
	prompt = ft_strjoin(user, "@minishell");
	free(user);
	
	if (!hack.fail || hack.fail == -1)
		prompt2 = ft_strjoin(prompt, BLUE);
	else
		prompt2 = ft_strjoin(prompt, RED);
	free(prompt);
	prompt = ft_strjoin(prompt2, "$ ");
	free(prompt2);
	prompt2 = ft_strjoin(prompt, DEFAULT);
	free(prompt);
	return (prompt2);
}
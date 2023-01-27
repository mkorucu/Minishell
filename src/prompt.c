#include "../lib/minishell.h"

static char	*get_user(t_prompt prompt)
{
	char	**user;

	user = NULL;
	exec_custom(&user, "/usr/bin/whoami", "whoami", prompt.envp);
	return (*user);
}

char	*mini_getprompt()
{
	char	*user;
	char	*prompt;
	char	*prompt2;

	user = get_user(hack.prompt);
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
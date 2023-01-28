#include "../lib/minishell.h"

void	init_app(void)
{
	errno = 0;
	crime.paths = NULL;
	crime.parent_pid = getpid();
}
void	init_env(char **env)
{
	int		i;
	
	i = 0;
	while(env[i])
		i++;
	crime.env = ft_calloc(sizeof(char **), i + 1);
	while(i--)
		crime.env[i] = ft_strdup(env[i]);
}
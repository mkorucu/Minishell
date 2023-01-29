#include "../lib/minishell.h"

void	init_env(char **env)
{
	int	i;
	int	j;

	while(env[i])
		i++;
	crime.env = ft_calloc(sizeof(char*), i + 1);
	while (i--)
		crime.env[i] = ft_strdup(env[i]);
	crime.user = get_env("USER");
}
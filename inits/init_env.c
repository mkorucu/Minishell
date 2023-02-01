#include "../lib/minishell.h"

void	init_env(char **env)
{
	int	i;
	int	j;

	while(env[i])
		i++;
	g_crime.env = ft_calloc(sizeof(char*), i + 1);
	while (i--)
		g_crime.env[i] = ft_strdup(env[i]);
	g_crime.user = get_env("USER");
}
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
	while(env[++i])
	{
		if (!ft_strncmp(env[i], "USER=", 5))
		{
			j = 5;
			while(env[i][j] != '\0')
				j++;
			crime.user = ft_calloc(sizeof(char), j - 4);
			crime.user = ft_strdup(&env[i][5]);
		}
	}
}
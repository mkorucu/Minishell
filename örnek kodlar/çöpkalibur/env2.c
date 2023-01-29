#include "minishell.h"

void	access_env()
{
	int	i;

	i = 0;
	if (!ft_strncmp(hack.read2[0], "env\0", 4) && !hack.read2[1])
	{
		while (hack.envp[i])
		{
			printf("%s\n", hack.envp[i]);
			i++;
		}
	}
	else
		printf("zsh: command not found: %s\n", hack.read1);
}

void env_init(char *env)
{
	int	i;
	int	j;
	char **env2;

	i = 0;
	env2 = malloc(sizeof(char *) * ft_strlen2(env) + 1);
	while(env[i])
	{
		j = 0;
		env2[i] = malloc(sizeof(char) * ft_strlen(env[i]) + 1);
		while (env[i][j])
		{
			env2[i][j] = env[i][j];
			j++;
		}
		i++;
	}
	hack.envp = env2;
}

char *mini_env(char *var, int n)
{
	int i;
	int n2;

	i = 0;
	//if(n < 0)
	//	n = ft_strlen(var);
	while(!ft_strchr(var, "=") && hack.envp && hack.envp[i])
	{
		n2 = n;
		
	}
	
}
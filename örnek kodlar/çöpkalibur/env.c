/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:35:07 by bkeklik           #+#    #+#             */
/*   Updated: 2022/12/23 12:05:09 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	access_env(t_data *data)
{
	int	i;

	i = 0;
	if (!ft_strncmp(data->read2[0], "env\0", 4) && !data->read2[1])
	{
		while (data->env[i])
		{
			printf("%s\n", data->env[i]);
			i++;
		}
	}
	else
		printf("zsh: command not found: %s\n", data->read1);
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
	hack.env = env2;
}
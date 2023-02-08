/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:17 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 21:16:14 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_env(char *data)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *), env_len() + 1);
	while (g_crime.env[i])
	{
		if (ft_strncmp(g_crime.env[i], data, ft_strlen(data)))
		{
			new_env[j] = ft_strdup(g_crime.env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	free_array(g_crime.env);
	g_crime.env = new_env;
}

void	builtin_unset(char **input)
{
	char	*data;

	input++;
	while (*input)
	{
		data = ft_strjoin(*input, "=");
		remove_env(data);
		free(data);
		input++;
	}
	set_paths();
	if (!(g_crime.parent_pid == getpid()))
		exit (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:11:09 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 16:00:14 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

int	env_len(void)
{
	char	**env;

	env = g_crime.env;
	while (*env)
		env++;
	return (env - g_crime.env);
}

int	check_env(char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head)
		return (0);
	if (head == str)
		return (0);
	while (*str)
	{
		if (is_whitespace(*str))
			return (0);
		str++;
	}
	return (1);
}

void	add_env(char *str)
{
	int		i;
	char	**env;
	char	**new_env;

	i = 0;
	env = g_crime.env;
	new_env = ft_calloc(sizeof(char **), env_len() + 2);
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	g_crime.env = new_env;
}

int	is_include(char *str)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = g_crime.env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

void	builtin_export(char **input)
{
	int		pos;
	char	*tmp;

	input++;
	while (*input)
	{
		if (check_env(*input))
		{
			pos = is_include(*input);
			if (pos != -1)
			{
				tmp = g_crime.env[pos];
				g_ms.env[pos] = ft_strdup(*input);
				free(tmp);
			}
			else
				add_env(*input);
		}
		input++;
	}
	set_paths();
	if (!(g_crime.parent_pid == get_pid()))
		exit (EXIT_SUCCESS);
}

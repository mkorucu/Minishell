/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:45:26 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/21 03:19:22 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env_checker(char *str)
{
	char	*head;
	
	head = ft_strchr(str, '=');
	if (!head || head == str)
		return (0);
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			return (0);
		str++;
	}
	return (1);
	
}

int	ft_is_included(char *str)
{
	int	i;
	int	j;
	char	**env;

	i = 0;
	env = hack.env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break;
			j++;
		}	
		i++;
	}
	return (-1);
}

void	builtin_export(char **execute)
{
	int		pos;
	char	*tmp;
	int		i;
	
	i = 1;
	while(execute[i])
	{
		if (ft_env_checker(*execute))
		{
			pos = ft_is_included(*execute);
			if (pos != -1)
			{
				tmp = hack.env[pos];
				hack.env[pos] = ft_strdup(*execute);
				free (tmp);
			}
			else
				add_env(*execute);
		}
		execute++;
	}
	ft_set_paths();
	if (hack.parent_pid != getpid())
		exit(EXIT_SUCCESS);
}
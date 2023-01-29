/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:31:49 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/21 03:54:45 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_split_env(char *str)
{
	while (*str != '=')
		str++;
	str++;
	return (ft_strdup(str));
}

char	*ft_get_env(char *str)
{
	size_t	len;
	char	**env;
	char	*new_str;

	env = hack.env;
	new_str = ft_strjoin(str, "=");
	len = ft_strlen(new_str);
	while(*env)
	{
		if (!ft_strncmp(*env, new_str, len))
		{
			free(new_str);
			return (ft_split_env(*env));
		}
		env++;
	}
	free(new_str);
	return (ft_calloc(sizeof(char *),1));
}
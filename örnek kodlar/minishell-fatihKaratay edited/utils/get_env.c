/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:03 by fkaratay          #+#    #+#             */
/*   Updated: 2023/01/29 19:15:20 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*split_env(char *str)
{
	while (*str != '=')
		str++;
	str++;
	return (ft_strdup(str));
}

char	*get_env(char *str)
{
	int		i;
	int		len;
	char	*curr;


	curr = ft_strjoin(str, "=");
	i = 0;
	len = ft_strlen(curr);
	while (g_ms.env[i])
	{
		if (!ft_strncmp(g_ms.env[i], curr, len))
		{
			free(curr);
			return (ft_strdup(&g_ms.env[i][len]));
		}
		i++;
	}
	free (curr);
	return (ft_calloc(sizeof(char *), 1));
}

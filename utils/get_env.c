/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:59:00 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/01 10:49:25 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

char	*get_env(char *str)
{
	int		i;
	int		len;
	char	*curr;


	curr = ft_strjoin(str, "=");
	i = -1;
	len = ft_strlen(curr);
	while (g_crime.env[++i])
	{
		if (!ft_strncmp(g_crime.env[i], curr, len))
		{
			free(curr);
			return (ft_strdup(&g_crime.env[i][len]));
		}
	}
	free (curr);
	return (ft_calloc(sizeof(char *), 1));
}
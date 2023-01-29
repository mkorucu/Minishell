/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:59:00 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/29 19:15:07 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

char	*get_env(char *str)
{
	int		i;
	int		len;
	char	*curr;


	curr = ft_strjoin(str, "=");
	i = 0;
	len = ft_strlen(curr);
	while (crime.env[i])
	{
		if (!ft_strncmp(crime.env[i], curr, len))
		{
			free(curr);
			return (ft_strdup(&crime.env[i][len]));
		}
		i++;
	}
	free (curr);
	return (ft_calloc(sizeof(char *), 1));
}
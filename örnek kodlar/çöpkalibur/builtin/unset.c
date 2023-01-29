/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:56:44 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/21 03:59:47 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void	ft_remove_env(char *str)
{
	int		i;
	int		j;
	char	new_env;


	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *),env_len()+ ü1);
	
}
void	builtin_unset(char **execute)
{
	char *data;
	execute++;
	while (*execute)
	{
		data = ft_strjoin(*execute, "=");
		re	
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:04:36 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/30 17:53:10 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

char	**add_array(char **execute, char *new_str)
{
	int	i;
	int	len;
	int	**new_exec;

	len = 0;
	while (execute && execute[len])
		len++;
	new_exec = ft_calloc(sizeof(char *), len + 2);
	i = 0;
	while (++i < len)
		new_exec[i] = execute[i];
	new_exec[i] = new_str;
	free(execute);
	return (new_str);
}
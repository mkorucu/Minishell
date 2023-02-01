/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:51:40 by fkaratay          #+#    #+#             */
/*   Updated: 2023/02/01 11:49:29 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**push_array(char **arg_arr, char *str)
{
	int		i;
	int		len;
	char	**new_exec;

	len = 0;
	while (arg_arr && arg_arr[len])
		len++;
	new_exec = ft_calloc(sizeof(char *), len + 2);
	i = -1;
	while (++i < len)
		new_exec[i] = arg_arr[i];
	new_exec[i] = str;
	free(arg_arr);
	return (new_exec);
}

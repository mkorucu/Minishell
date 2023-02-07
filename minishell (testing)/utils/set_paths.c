/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btekinli <btekinli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:21 by btekinli          #+#    #+#             */
/*   Updated: 2022/10/13 02:40:24 by btekinli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_paths(void)
{
	char	*path;

	if (g_ms.paths)
		free_array(g_ms.paths);
	path = get_env("PATH");
	if (!(*path))
		g_ms.paths = NULL;
	else
		g_ms.paths = ft_split(path, ':');
	free(path);
}

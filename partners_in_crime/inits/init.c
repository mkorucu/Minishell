/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:55:02 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/06 20:17:53 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	init(char **env)
{
	char	*path;

	g_crime.env = env;
	g_crime.user = get_env("USER");
	if (g_crime.paths)
		kill_him(g_crime.paths);
	path = get_env("PATH");
	if (!(*path))
		g_crime.paths = NULL;
	else
		g_crime.paths = ft_split(path, ':');
	free(path);
}

void	commit_an_offense(void)
{
	errno = 0;
	g_crime.paths = NULL;
	g_crime.parent_pid = getpid();
}

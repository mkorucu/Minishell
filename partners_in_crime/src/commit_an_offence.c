/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commit_an_offence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:30:02 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/07 10:59:09 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	commit_an_offense(char **env)
{
	char	*path;

	errno = 0;
	g_crime.fail = 0;
	g_crime.paths = NULL;
	g_crime.parent_pid = getpid();
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

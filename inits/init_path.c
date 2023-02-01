/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:51:24 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/01 10:47:55 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	init_path(void)
{
	char	*path;

	if (g_crime.paths)
		kill_array(g_crime.paths);
	path = get_env("PATH");
	if (!(*path))
		g_crime.paths = NULL;
	else
		g_crime.paths = ft_split(path, ':');
	free(path);
}

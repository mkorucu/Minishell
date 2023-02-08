/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:45:02 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/08 17:16:50 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_paths(void)
{
	char	*path;

	if (g_crime.paths)
		free_array(g_crime.paths);
	path = get_env("PATH");
	if (!(*path))
		g_crime.paths = NULL;
	else
		g_crime.paths = ft_split(path, ':');
	free(path);
}

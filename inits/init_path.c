/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:51:24 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/29 19:59:40 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	init_path(void)
{
	char	*path;

	if (crime.paths)
		kill_array(crime.paths);
	path = get_env("PATH");
	if (!(*path))
		crime.paths = NULL;
	else
		crime.paths = ft_split(path, ':');
	free(path);
}

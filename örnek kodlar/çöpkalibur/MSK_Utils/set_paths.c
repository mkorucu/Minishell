/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:04:48 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/21 03:55:45 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_paths()
{
	char	*path;

	if (hack.paths)
		ft_free_array(hack.paths);
	path = ft_get_env("PATH");
	if (!(*path))
		hack.paths = NULL;
		else
			hack.paths = ft_split(path, ':');
	free(path);
}

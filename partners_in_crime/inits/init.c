/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:55:02 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/01 13:07:51 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	init(char **env)
{
	init_env(env);
	init_path();
}

void	commit_an_offense(void)
{
	errno = 0;
	g_crime.paths = NULL;
	g_crime.parent_pid = getpid();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:55:02 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/01 10:58:33 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	init(env)
{
	init_env(env);
	init_path();
}

void	commit_an_offense()
{
	errno = 0;
	g_crime.paths = NULL;
	g_crime.parent_pid = getpid();
}

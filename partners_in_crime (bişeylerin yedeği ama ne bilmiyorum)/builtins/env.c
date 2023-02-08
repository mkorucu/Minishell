/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:07:57 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 15:16:11 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	builtin_env(void)
{
	char	**env;

	env = g_crime.env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	if (!(g_crime.parent_pid == get_pid()))
		exit (EXIT_SUCCESS);
}

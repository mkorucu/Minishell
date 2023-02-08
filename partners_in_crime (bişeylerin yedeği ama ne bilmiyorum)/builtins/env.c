/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:07:57 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 17:02:20 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(void)
{
	char	**env;

	env = g_crime.env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	if (!(g_crime.parent_pid == getpid()))
		exit (EXIT_SUCCESS);
}

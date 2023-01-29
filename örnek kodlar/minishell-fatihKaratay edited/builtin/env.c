/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:14 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 02:36:26 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(void)
{
	char	**env;

	env = g_ms.env;
	while (*env)
	{
		printf("%s\n",*env);
		env++;
	}
	if (!(g_ms.parent_pid == getpid()))
		exit (EXIT_SUCCESS);	
}

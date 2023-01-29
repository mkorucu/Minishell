/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:00:31 by mkorucu           #+#    #+#             */
/*   Updated: 2022/12/23 12:14:28 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(void)
{
		char	**env;

		env = hack.env;
		while (*env)
		{
			printf("%s\n",*env);
			env++;
		}
		if (!hack.parent_pid == getpid())
			exit (EXIT_SUCCESS);
		
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:00:31 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/29 19:07:48 by bkeklik          ###   ########.fr       */
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
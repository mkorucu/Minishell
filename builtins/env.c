/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:07:57 by bkeklik           #+#    #+#             */
/*   Updated: 2023/01/29 19:09:40 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	builtin_env(void)
{
		char	**env;

		env = crime.env;
		while (*env)
		{
			printf("%s\n",*env);
			env++;
		}
		if (!crime.parent_pid == getpid())
			exit (EXIT_SUCCESS);
}

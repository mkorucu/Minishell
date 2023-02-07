/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btekinli <btekinli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:14 by btekinli          #+#    #+#             */
/*   Updated: 2022/10/13 02:36:26 by btekinli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(void)
{
	char	**env;

	env = g_ms.env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	if (!is_parent())
		exit (EXIT_SUCCESS);
}

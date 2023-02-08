/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:41:37 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/08 15:09:48 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	builtin_cd(char **input)
{
	char	*home;

	if (input[1] != NULL)
	{
		if (chdir(input[1]) != 0)
		{
			errno = 1;
			write(2, "minishell : No such file or directory\n", 38);
			strerror(errno);
		}	
	}
	else
	{
		home = getenv("HOME");
		if (home && *home)
			if (chdir(home))
				perror("minishell ");
	}
	if (!g_crime.parent_pid == getpid())
		exit (errno);
}

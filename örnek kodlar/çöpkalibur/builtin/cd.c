/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:11:53 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/21 01:45:16 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(char **execute)
{
	
	if (execute[1] == NULL)
	{
		if (chdir(getenv("HOME")))
			perror("minishell ");
	}
	else
	{
		if(chdir(execute[1]) != 0)
			perror("minishell ");
	}
	if (hack.parent_pid != getpid())
		exit(errno);
}
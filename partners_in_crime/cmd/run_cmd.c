/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:26:28 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/06 20:17:56 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	run_cmd(t_process *process)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		route_cmd(process);
		run_builtin(process->execute);
		path = get_path(*process->execute);
		execve(path, process->execute, g_crime.env);
		cmd_err(*process->execute);
		exit(errno);
	}
	else
		process->pid = pid;
}
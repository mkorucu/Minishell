/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:26:28 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/06 20:32:22 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	route_cmd(t_process *process)
{
	if (g_crime.process > 1)
	{
		if (contain_heredoc(process))
		{
			dup2(process->heredoc_fd[0], 0);
			if (process->next != NULL)
				dup2(process->fd[1], 1);
		}
		else
		{
			if (process->prev == NULL)
				dup2(process->fd[1], 1);
			else if (process->next == NULL)
				dup2(process->prev->fd[0], 0);
			else
			{
				dup2(process->prev->fd[0], 0);
				dup2(process->fd[1], 1);
			}
		}
	}
	get_all_inputs(process);
	set_all_outputs(process);
	close_fd_all();
}

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
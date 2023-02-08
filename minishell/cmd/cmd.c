/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:58:01 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/08 16:51:12 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	start_builtin(t_process	*process)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(2);
	get_all_inputs(process);
	set_all_outputs(process);
	run_builtin(process->execute);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void	pause_cmd(void)
{
	t_process	*process;

	process = g_crime.process;
	close_fd_all();
	while (process)
	{
		if (process->pid != -1)
		{
			waitpid(process->pid, &errno, 0);
			errno = WEXITSTATUS(errno);
		}
		process = process->next;
	}
}

void	start_cmd(void)
{
	t_process	*process;

	process = g_crime.process;
	if (!process)
		return ;
	fill_all_heredoc();
	if (g_crime.fail)
		return (close_fd_all());
	if (is_builtin(*process->execute) && g_crime.process_count == 1)
	{
		start_builtin(process);
		process = process->next;
	}
	while (process)
	{
		run_cmd(process);
		process = process->next;
	}
	pause_cmd();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:56:52 by fkaratay          #+#    #+#             */
/*   Updated: 2023/02/04 15:43:33 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_heredoc_fd(t_process *process)
{
	if (contain_heredoc(process) && process->heredoc_fd[0] > 2)
		close(process->heredoc_fd[0]);
}

void	close_all_fd(void)
{
	t_process	*process;

	process = g_ms.process;
	while (process)
	{
		close_heredoc_fd(process);
		if (process->fd[0] > 2)
			close(process->fd[0]);
		if (process->fd[1] > 2)
			close(process->fd[1]);
		process = process->next;
	}
}

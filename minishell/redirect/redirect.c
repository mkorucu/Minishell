/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:57:54 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/11 20:50:23 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_all_inputs(t_process *process)
{
	int		i;
	int		fd;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (!(ft_strncmp(process->redirects[i], "<", 1)))
		{
			fd = open(redirects[i + 1], O_RDONLY);
			if (fd == -1)
				return (no_file_err(redirects[i + 1]));
			else
			{
				dup2(fd, 0);
				close(fd);
			}
		}	
		else if (!ft_strncmp(process->redirects[i], "<<", 2))
			dup2(process->heredoc_fd[0], 0);
		i += 2;
	}
}

void	set_all_outputs(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (ft_strcmp(redirects[i], ">"))
			output(redirects[i + 1], 1);
		else if (ft_strcmp(redirects[i], ">>"))
			output(redirects[i + 1], 0);
		i += 2;
	}
}

void	fill_all_heredoc(void)
{
	int			i;
	char		**redirects;
	t_process	*process;

	process = g_crime.process;
	while (process)
	{
		i = 0;
		redirects = process->redirects;
		while (redirects[i] && !(g_crime.ignore))
		{
			if (!ft_strncmp(redirects[i], "<<", 2))
				heredoc(process->heredoc_fd, redirects[i + 1]);
			i += 2;
		}
		process = process->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:00:11 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/01 21:01:02 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	close_heredoc(int sig)
{
	(void)sig;
	g_crime.fail = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	heredoc(int *fd, char *endline)
{
	char		*input;
	static int	start = 0;

	if (start)
	{
		start = 1;
		close(fd[0]);
		close(fd[1]);
	}
	if (pipe(fd) < 0)
		return (perror("minishell"));
	while (1)
	{
		signal(SIGINT, &close_heredoc);
		input = readline("heredoc>> ");
		if (!input || ft_strcmp(input, endline) || g_crime.fail)
		{
			free(input);
			break ;
		}
		write(fd[1], input, ft_strlen(input));
		write(fd[1], "\n", 1);
		free(input);
	}
	close(fd[1]);
}

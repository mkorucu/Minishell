/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:17:24 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/08 16:51:12 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_heredoc(int sig)
{
	(void)sig;
	g_crime.fail = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_crime.fail = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		write(1, "\033[A", 3);
	}
}

void	handle_exit(char *str)
{
	if (!str)
	{
		printf("exit\n");
		exit(errno);
	}
}

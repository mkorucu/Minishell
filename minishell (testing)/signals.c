/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:11:58 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/08 14:13:27 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	close_heredoc(int sig)
{
	(void)sig;
	g_ms.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_ms.ignore = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		write(1, "\033[A", 3);
	}
}

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit(errno);
	}
}
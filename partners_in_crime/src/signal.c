/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:46:02 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/06 23:37:05 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

t_data	g_crime;

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

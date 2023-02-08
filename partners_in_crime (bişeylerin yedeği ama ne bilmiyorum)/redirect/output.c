/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:30:18 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 15:31:31 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	output(char *file, int mode)
{
	int		fd;

	fd = 0;
	if (mode == 1)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (mode == 0)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd == -1)
	{
		perror("minishell");
		if (g_crime.parent_pid == getpid())
			return ;
		else
			exit(errno);
	}
	dup2(fd, 1);
	close(fd);
}

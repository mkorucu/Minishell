/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:11:39 by btekinli          #+#    #+#             */
/*   Updated: 2023/02/08 15:30:35 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	output(char *file, int mode)
{
	int		fd;

	fd = 0;
	if (mode == REPLACE)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (mode == APPEND)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd == -1)
	{
		perror("minishell");
		if (is_parent())
			return ;
		else
			exit(errno);
	}
	dup2(fd, 1);
	close(fd);
}

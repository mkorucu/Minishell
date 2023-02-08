/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:00:04 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/08 17:15:49 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_error(char *str)
{
	errno = 127;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
	if (!(g_crime.parent_pid == getpid()))
		exit(errno);
}

void	no_file_err(char *str)
{
	if (ft_strchr(str, '/'))
		errno = 127;
	else
		errno = 1;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
	if ((!(g_crime.parent_pid == getpid())))
		exit(errno);
}

void	directory_err(char *str)
{
	errno = 126;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": is a directory\n", 17);
	if (!(g_crime.parent_pid == getpid()))
		exit(errno);
}

void	chain_err(int type)
{
	char	*red;

	if (type == HERE_DOC)
		red = "<<";
	else if (type == RED_INPUT)
		red = "<";
	else if (type == RED_OUTPUT)
		red = ">";
	else if (type == RED_APPEND)
		red = ">>";
	else if (type == PIPE)
		red = "|";
	else
		red = "newline";
	errno = 258;
	write(2, "minishell: syntax error near unexpected token '", 47);
	write(2, red, ft_strlen(red));
	write(2, "'\n", 2);
}

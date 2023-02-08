/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:07:23 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 17:01:56 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(char **input)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	if (input[i] && ft_strcmp(input[i], "-n"))
		i++;
	if (i > 1)
		flag = 0;
	while (input[i])
	{
		ft_putstr_fd(input[i], 1);
		if (input[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (flag)
		write(STDOUT_FILENO, "\n", 1);
	if (!(g_crime.parent_pid == getpid()))
		exit(EXIT_SUCCESS);
}

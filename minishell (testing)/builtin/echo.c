/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:12 by btekinli          #+#    #+#             */
/*   Updated: 2023/02/08 12:47:18 by mkorucu          ###   ########.fr       */
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
	if (!is_parent())
		exit(EXIT_SUCCESS);
}
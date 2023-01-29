/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:18:03 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/21 02:14:04 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(char **execute)
{
	int	i;
	int	flag;

	i = 1;
	while (execute[i] && ft_strncmp(execute[i], "-n", 3))
		i++;
	flag = 1;
	if (i > 1)
		flag = 0;
	while (execute[i])
	{
		printf(execute[i]);
		if (execute[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (flag)
		write(1, "\n", 1);
	if (!is_parent())
		exit(EXIT_SUCCESS);
	
}
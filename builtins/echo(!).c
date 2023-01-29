/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:07:23 by bkeklik           #+#    #+#             */
/*   Updated: 2023/01/29 19:07:33 by bkeklik          ###   ########.fr       */
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
		printf("%s\n", execute[i]);
		if (execute[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (flag)
		write(1, "\n", 1);
	if (!is_parent())
		exit(EXIT_SUCCESS);
}

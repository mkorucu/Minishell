/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btekinli <btekinli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:12 by btekinli          #+#    #+#             */
/*   Updated: 2022/10/13 11:59:04 by btekinli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_char(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		write(STDOUT_FILENO, &(input[i]), 1);
		i++;
	}
}

int	skip_flag(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strcmp(str[i], "-n"))
			i++;
		else
			break ;
	}
	return (i);
}

void	builtin_echo(char **input)
{
	int	i;
	int	flag;

	i = 1;
	flag = TRUE;
	i = skip_flag(input);
	if (i > 1)
		flag = FALSE;
	while (input[i])
	{
		put_char(input[i]);
		if (input[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (flag)
		write(STDOUT_FILENO, "\n", 1);
	if (!is_parent())
		exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:33:36 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/21 01:44:47 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_arg_count(char **argv)
{
	int	i;
	
	i = 1;
	while(argv[i])
		i++;
	return (i);
}

int	ft_number_check(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '+' || *str == '-')
			str++;
		else
			return (0);
	}
	return (1);
}

void	builtin_exit(char **execute)
{
	if (ft_arg_count == 1)
	{
		printf("exit\n");
		exit(errno);
	}
	else
	{
		if (ft_number_check(execute[1]))
		{
			if (ft_arg_count(execute) > 2)
			{
				write(2, "exit\nminishell: exit: too many arguments\n", 41);
				errno = 1;
				return ;
			}
			exit(ft_atoi(execute[1]) % 256);
		}
		write(2, "exit\nminishell: exit: numeric argument required\n", 48);
		exit(-1 % 256);
	}
}
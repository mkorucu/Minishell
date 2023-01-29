/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:56:44 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/27 20:20:57 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"




void	exec_builtins(char **execute)
{
	if (ft_strcmp(execute, "pwd"))
		builtin_pwd();
	else if (ft_strcmp(execute, "env"))
		builtin_env();
	else if (ft_strcmp(execute, "cd"))
		builtin_cd(execute);
	else if (ft_strcmp(execute, "echo"))
		builtin_echo(execute);
	else if (ft_strcmp(execute, "exit"))
		builtin_exit(exec_builtins);
	else if (ft_strcmp(execute, "unset"))
		builtin_unset(execute);
	else if (ft_strcmp(execute, "export"))
		builtin_export(execute);
}
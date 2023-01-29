/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:58:54 by bkeklik           #+#    #+#             */
/*   Updated: 2022/12/23 12:15:07 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(void)
{
	char	cwd[1024];
	chdir("/path/to/change/directory/to");
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
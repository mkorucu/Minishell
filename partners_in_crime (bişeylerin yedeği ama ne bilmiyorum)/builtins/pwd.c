/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:10:04 by bkeklik           #+#    #+#             */
/*   Updated: 2023/01/29 19:10:18 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	builtin_pwd(void)
{
	char	cwd[1024];
	chdir("/path/to/change/directory/to");
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}

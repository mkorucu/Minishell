/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:10:04 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 17:03:34 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(void)
{
	char	*result;

	result = NULL;
	result = getcwd(result, sizeof(result));
	if (!result)
		perror("minishell ");
	else
		printf("%s\n", result);
	free(result);
	if (!(g_crime.parent_pid == getpid()))
		exit(errno);
}

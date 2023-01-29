/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:12 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 11:59:04 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
*/
void	builtin_echo(char **execute)
{
	int	i;

	i = 1;
	while (execute[i] && ft_strncmp(execute[i], "-n", 3))
		i++;
	g_ms.flag = 1;
	if (i > 1)
		g_ms.flag = 0;
	while (execute[i])
	{
		printf("%s\n", execute[i]);
		if (execute[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (g_ms.flag)
		write(1, "\n", 1);
	if (!is_parent())
		exit(EXIT_SUCCESS);
}

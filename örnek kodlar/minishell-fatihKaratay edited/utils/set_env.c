/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:18 by fkaratay          #+#    #+#             */
/*   Updated: 2023/01/29 19:06:10 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_env(char **env)
{
	int		i;
	i = 0;
	while(env[i])
		i++;
	g_ms.env = ft_calloc(sizeof(char **), i + 1);
	while(i--)
		g_ms.env[i] = ft_strdup(env[i]);
	g_ms.user = get_env("USER");
}
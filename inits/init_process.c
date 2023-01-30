/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:51:42 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/30 15:37:30 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	init_process(t_process **new_process)
{
	*new_process = ft_calloc(sizeof(t_process), 1);
	pipe((*new_process)->fd);
	(*new_process)->pid = -1;
	(*new_process)->execute = ft_calloc(sizeof(char *), 1);
	(*new_process)->redirects = ft_calloc(sizeof(char *), 1);
	(*new_process)->prev = NULL;
	(*new_process)->next = NULL;
}
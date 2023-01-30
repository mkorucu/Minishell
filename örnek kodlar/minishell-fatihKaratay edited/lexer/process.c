/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:10:01 by fkaratay          #+#    #+#             */
/*   Updated: 2023/01/30 15:09:22 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		init_process(t_process **new_process)
{
	*new_process = ft_calloc(sizeof(t_process), 1);
	pipe((*new_process)->fd);
	(*new_process)->pid = -1;
	(*new_process)->execute = ft_calloc(sizeof(char *), 1);
	(*new_process)->redirects = ft_calloc(sizeof(char *), 1);
	(*new_process)->prev = NULL;
	(*new_process)->next = NULL;
}

void	process_addback(t_process **process, t_process *new_process)
{
	t_process	*i_process;

	i_process = *process;
	if (!(i_process))
		*process = new_process;
	else
	{
		while (i_process->next)
			i_process = i_process->next;
		i_process->next = new_process;
		new_process->prev = i_process;
	}
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:51:42 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/30 15:40:27 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	add_process(t_process **list, t_process *new_process)
{
	t_process	*curr;
	
	curr = *list;
	if (!curr)
		*list = new_process;
	else
	{	
		while (!curr)
			curr = curr->next;
		curr->next = new_process;
		new_process->prev = curr;
	}
}
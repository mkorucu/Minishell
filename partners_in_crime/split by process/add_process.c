/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:51:42 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/01 15:18:11 by bkeklik          ###   ########.fr       */
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

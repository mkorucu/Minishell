/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:46:31 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/01 15:20:01 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

int	list_arguments(t_chain **chain, t_process *process)
{
	char	*str;

	if ((*chain)->type == STRING)
	{
		str = remove_quotes((*chain)->str); //DAHA YAZMADIM
		process->execute = add_array(process->execute, str);
	}
	else
	{
		str = remove_quotes((*chain)->str);
		process->redirects = add_array(process->redirects, str);
		*chain = (*chain)->next;
		if (!(*chain) || (*chain)->type != STRING)
		{
			free_chain();
			if (!(chain))
				chain_error(0);
			else
				chain_error((*chain)->type);
			return (0);
		}
		str = remove_quotes((*chain)->str);
		process->execute = add_array(process->execute, str);
	}
	return (1);
}

int	listing_process(void)
{
	t_process	*p_curr;
	t_chain		*c_curr;

	c_curr = g_crime.chain;

	while (c_curr)
	{
		if (c_curr->type == PIPE || c_curr->prev == NULL)
		{
			if (c_curr->type == PIPE)
				c_curr = c_curr->next;
			init_process(&p_curr);
			add_process(&g_crime.process, p_curr);
			g_crime.process_count++;
		}
		if (!c_curr)
			break ;
		if (!list_arguments(&c_curr, p_curr))
			return (0);
		if (c_curr)
			c_curr = c_curr->next;
	}
	free_chain();
	return (1);
}
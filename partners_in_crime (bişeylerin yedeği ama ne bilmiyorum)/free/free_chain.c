/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:10:52 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/07 12:15:35 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	free_chain()
{
	t_chain	*chain;
	t_chain	*curr;
	
	chain = g_crime.chain;
	while(chain)
	{
		curr = chain;
		chain = chain->next;
		free(curr);
	}
}
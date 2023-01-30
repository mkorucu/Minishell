/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:10:52 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/30 16:23:29 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	free_chain()
{
	t_chain	*curr;
	t_chain	*curr2;
	
	curr = crime.chain;
	while(curr)
	{
		curr2 = curr;
		curr = curr->next;
		free(curr2);
	}
}
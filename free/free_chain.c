/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:10:52 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/01 10:47:17 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	free_chain()
{
	t_chain	*curr;
	t_chain	*curr2;
	
	curr = g_crime.chain;
	while(curr)
	{
		curr2 = curr;
		curr = curr->next;
		free(curr2);
	}
}
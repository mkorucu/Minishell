/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:53:56 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/08 21:35:36 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_chain	*new_list(char *str, enum e_ttype type)
{
	t_chain	*new_chain;

	new_chain = ft_calloc(sizeof(t_chain), 1);
	new_chain->type = type;
	new_chain->str = str;
	new_chain->prev = NULL;
	new_chain->next = NULL;
	return (new_chain);
}

int	add_list(t_chain **chain, t_chain *new_chain)
{
	t_chain	*curr;

	curr = *chain;
	if (!curr)
		*chain = new_chain;
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_chain;
		new_chain->prev = curr;
	}
	return (ft_strlen(new_chain->str));
}

void	listing(char *input)
{
	while (*input)
	{
		if (!ft_strncmp(input, ">>", 2))
			input += add_list(&g_crime.chain, new_list(ft_strdup(">>"), RED_APPEND));
		else if (!ft_strncmp(input, "<<", 2))
			input += add_list(&g_crime.chain, new_list(ft_strdup("<<"), HERE_DOC));
		else if (!ft_strncmp(input, "|", 1))
			input += add_list(&g_crime.chain, new_list(ft_strdup("|"), PIPE));
		else if (!ft_strncmp(input, "<", 1))
			input += add_list(&g_crime.chain, new_list(ft_strdup("<"), RED_INPUT));
		else if (!ft_strncmp(input, ">", 1))
			input += add_list(&g_crime.chain, new_list(ft_strdup(">"), RED_OUTPUT));
		else
			str_listing(&input);
	}
}

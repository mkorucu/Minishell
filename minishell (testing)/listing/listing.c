/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:13:13 by btekinli          #+#    #+#             */
/*   Updated: 2023/02/07 12:13:06 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*new_list(char *str, enum e_ttype type)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	token->type = type;
	token->str = str;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

int	add_list(t_token **chain, t_token *new_chain)
{
	t_token *curr;

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
			input += add_list(&g_ms.token, new_list(">>", RED_APPEND));
		else if (!ft_strncmp(input, "<<", 2))
			input += add_list(&g_ms.token, new_list("<<", HERE_DOC));
		else if (!ft_strncmp(input, "|", 1))
			input += add_list(&g_ms.token, new_list("|", PIPE));
		else if (!ft_strncmp(input, "<", 1))
			input += add_list(&g_ms.token, new_list("<", RED_INPUT));
		else if (!ft_strncmp(input, ">", 1))
			input += add_list(&g_ms.token, new_list(">", RED_OUTPUT));
		else
			str_listing(&input);
	}
}

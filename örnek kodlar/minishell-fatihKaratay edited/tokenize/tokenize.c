/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:13:13 by fkaratay          #+#    #+#             */
/*   Updated: 2023/01/29 21:19:51 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*init_token(char *str, enum e_ttype type)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	token->type = type;
	token->str = str;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

int	token_addback(t_token **token, t_token *new_token, int plus)
{
	t_token	*i_token;

	i_token = *token;
	(void)plus;
	if (!i_token)
		*token = new_token;
	else
	{
		while (i_token->next)
			i_token = i_token->next;
		i_token->next = new_token;
		new_token->prev = i_token;
	}
	return (ft_strlen(new_token->str));
}

void	tokenize(char *str)
{
	while (*str)
	{		
		if (!ft_strncmp(str, ">>", 2))
			str += token_addback(&g_ms.token, init_token((">>"), \
			RED_APPEND), 2);
		else if (!ft_strncmp(str, "<<", 2))
			str += token_addback(&g_ms.token, init_token(("<<"), \
			HERE_DOC), 2);
		else if (!ft_strncmp(str, "|", 1))
			str += token_addback(&g_ms.token, init_token(("|"), \
			PIPE), 1);
		else if (!ft_strncmp(str, "<", 1))
			str += token_addback(&g_ms.token, init_token(("<"), \
			RED_INPUT), 1);
		else if (!ft_strncmp(str, ">", 1))
			str += token_addback(&g_ms.token, init_token((">"), \
			RED_OUTPUT), 1);
		else
			parse_token_string(&str);
	}
}

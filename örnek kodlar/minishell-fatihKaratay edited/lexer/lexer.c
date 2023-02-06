/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:08:25 by fkaratay          #+#    #+#             */
/*   Updated: 2023/02/06 17:59:43 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	append_arguments(t_token **token, t_process *process)
{
	char	*str;

	if ((*token)->type == STRING)
	{
		str = clean_quote((*token)->str); //DAHA YAZMADIM
		process->execute = push_array(process->execute, str);
	}
	else
	{
		str = clean_quote((*token)->str);
		process->redirects = push_array(process->redirects, str);
		*token = (*token)->next;
		if (!(*token) || (*token)->type != STRING)
		{
			free_token();
			if (!(token))
				token_err(0);
			else
				token_err((*token)->type);
			return (0);
		}
		str = clean_quote((*token)->str);
		process->execute = push_array(process->execute, str);
	}
	return (1);
}

int	lexer(void)
{
	t_token		*token;
	t_process	*process;

	token = g_ms.token;
	while (token)
	{
		if (token->type == PIPE || token->prev == NULL)
		{
			if (token->type == PIPE)
				token = token->next;
			init_process(&process);
			process_addback(&g_ms.process, process);
			g_ms.process_count++;
		}
		if (!token)
			break ;
		if (!append_arguments(&token, process))
			return (FALSE);
		if (token)
			token = token->next;
	}
	free_token();
	return (TRUE);
}

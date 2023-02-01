/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:13:04 by fkaratay          #+#    #+#             */
/*   Updated: 2023/02/01 15:44:55 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	str_check(char **str)
{
	if (!**str)
		return (0);
	if (*str[0] == '<' && *str[1] == '<')
		return (HERE_DOC);
	if (*str[0] == '>' && *str[1] == '>')
		return (RED_APPEND);
	if (*str[0] == '<')
		return (RED_INPUT);
	if (*str[0] == '>')
		return (RED_OUTPUT);
	if (*str[0] == '|')
		return (PIPE);
	if ((*str[0] == ' ') || (*str[0] == '\t'))
		return (1);
	return (0);
}

void	find_end_pos(char **str)
{
	char	type;

	if (**str == '"')
		type = DOUBLE_QUOTE;
	if (**str == '\'')
		type = SINGLE_QUOTE;
	(*str)++;
	while (**str)
	{
		if (**str == type)
		{
			(*str)++;
			if (str_check(&(*str)))
				break ;
			else
				while (**str && !(str_check(&(*str))))
					(*str)++;
			return ;
		}
		(*str)++;
	}
}

void	without_quote_parse(char **str)
{
	while (**str)
	{
		if (is_whitespace(**str))
			break ;
		if (is_operator(*str))
			break ;
		(*str)++;
	}
}

void	skip_whitespace(char **str, char **head)
{
	while (**str && is_whitespace(**str))
		(*str)++;
	*head = *str;
}


void	parse_token_string(char **str)
{
	int		len;
	char	*head = NULL;
	char	*token_str;

	while (**str && str_check(&(*str)))
		(*str)++;
	*head = *(*str);
	if (**str && ((**str == DOUBLE_QUOTE) || (**str == SINGLE_QUOTE)))
		find_end_pos(&(*str));
	else
	{
		if (!(str_check(&(*str))))
		{
			while (**str)
				(*str)++;
		}
	}	
	len = *str - head;
	if (len > 0)
	{
		token_str = ft_substr(head, 0, len);
		token_addback(&g_ms.token, init_token(token_str, STRING), 0);
	}
}


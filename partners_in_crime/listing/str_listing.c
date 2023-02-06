/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_listing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:39:45 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/01 17:25:32 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

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
	if (*str == ' ' || *str == '\t')
		return (1);
	return (0);
}

void	string_found(char **str)
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

void	str_listing(char **str)
{
	int		len;
	char	*head;
	char	*token_str;

	while (**str && str_check(&(*str)))
		(*str)++;
	head = *str;
	if (**str && ((**str == DOUBLE_QUOTE) || (**str == SINGLE_QUOTE)))
		string_found(&(*str));
	else
	{
		if (!(str_check(&(*str))))
		{
			while (**str)
				*str++;
		}
	}
	len = *str - head;
	if (len > 0)
	{
		token_str = ft_substr(head, 0, len);
		add_list(&g_crime.chain, new_list(token_str, STRING));
	}
}
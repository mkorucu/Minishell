/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btekinli <btekinli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:55:44 by btekinli          #+#    #+#             */
/*   Updated: 2022/10/13 11:06:56 by btekinli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_op(char c)
{
	return ((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			(c >= '0' && c <= '9') || \
			(c == '_') || (c == '?'));
}

int	check_dollar(char *str)
{
	int		i;
	int		single_quote;
	int		double_quote;

	i = 0;
	single_quote = TRUE;
	double_quote = FALSE;
	while (str[i] && str[i] != DOLLAR_OP)
	{
		if (str[i] == SINGLE_QUOTE)
			single_quote = double_quote;
		if (str[i] == DOUBLE_QUOTE)
			double_quote = !double_quote;
		i++;
	}
	if (!valid_op(*(ft_strchr(str, DOLLAR_OP) + 1)))
		return (FALSE);
	return (single_quote);
}

static char	*get_str(char *str, int	*pos, int type)
{
	int		first;
	char	*data;

	first = *pos;
	while (str[*pos] != type)
		(*pos)++;
	data = ft_substr(str, first, *pos - first);
	(*pos)++;
	return (data);
}

char	*parse_dollar_op(char *str)
{
	int		i;
	int		first;
	char	*env;
	char	*result;
	char	*data;

	i = 0;
	result = NULL;
	data = get_str(str, &i, DOLLAR_OP);
	push_new_str(&result, data);
	first = i;
	if (str[i] == '?' && ++i)
		push_new_str(&result, ft_itoa(errno));
	else
	{
		while (valid_op(str[i]))
			(i)++;
		data = ft_substr(str, first, i - first);
		env = get_env(data);
		push_new_str(&result, env);
		free(data);
	}
	data = get_str(str, &i, 0);
	push_new_str(&result, data);
	return (result);
}

char	*dollar(char *str)
{
	char	*tmp;
	char	*new_str;

	new_str = ft_strdup(str);
	while (ft_strchr(new_str, DOLLAR_OP) && check_dollar(new_str))
	{
		tmp = new_str;
		new_str = parse_dollar_op(new_str);
		free(tmp);
	}
	return (new_str);
}

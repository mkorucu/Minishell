/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:51:54 by fkaratay          #+#    #+#             */
/*   Updated: 2022/10/13 11:06:45 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	push_new_str(char **new_str, char *str)
{
	char	*tmp;

	if (!(*new_str))
	{
		*new_str = ft_strdup(str);
		free(str);
		return ;
	}
	tmp = *new_str;
	*new_str = ft_strjoin(*new_str, str);
	free(tmp);
	free(str);
}

char	*clean_quote_with_type(char *str, int *pos, char type)
{
	int		first;
	char	*new_str;

	(*pos)++;
	first = *pos;
	while (str[*pos] && str[*pos] != type)
		(*pos)++;
	new_str = ft_substr(str, first, *pos - first);
	if (str[*pos])
		(*pos)++;
	return (new_str);
}

static char	*get_str(char *str, int	*pos)
{
	int	first;

	first = *pos;
	while (str[*pos] && str[*pos] != DOUBLE_QUOTE && str[*pos] != SINGLE_QUOTE)
		(*pos)++;
	return (ft_substr(str, first, *pos - first));
}

char	*clean_quote(char *str)
{
	int		i;
	char	*data;
	char	*result;

	i = 0;
	result = NULL;
	str = dollar(str);
	while (str[i])
	{
		if (str[i] == DOUBLE_QUOTE)
			data = clean_quote_with_type(str, &i, DOUBLE_QUOTE);
		else if (str[i] == SINGLE_QUOTE)
			data = clean_quote_with_type(str, &i, SINGLE_QUOTE);
		else
			data = get_str(str, &i);
		push_new_str(&result, data);
	}
	free(str);
	return (result);
}

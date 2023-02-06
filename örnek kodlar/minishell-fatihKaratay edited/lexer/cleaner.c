/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:51:54 by fkaratay          #+#    #+#             */
/*   Updated: 2023/02/06 20:28:22 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	push_new_str(char **trimed, char *removed)
{
	char	*tmp;

	if (!(*trimed))
	{
		*trimed = ft_strdup(removed);
		free(removed);
		return ;
	}
	tmp = *trimed;
	*trimed =  ft_strjoin(*trimed, removed);
	free(tmp);
	free(removed);
}



void	close_quote(int sig)
{
	(void)sig;
	g_ms.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

char	*clean_quote_with_type(char *str, int *pos, char type)
{
	int		start;
	char	*new_str;

	++*pos;
	start = *pos;
	while (str[*pos] && str[*pos] != type)
		++*pos;
	new_str = ft_substr(str, start, *pos - start);
	if (str[*pos])
		++*pos;
	return (new_str);
}

static char	*get_str(char *str, int	*i)
{
	int	start;

	start = *i;
	while (str[*i] && str[*i] != DOUBLE_QUOTE && str[*i] != SINGLE_QUOTE)
		(*i)++;
	return (ft_substr(str, start, *i - start));
}

char	*clean_quote(char *str)
{
	int		curr;
	char	*removed;
	char	*trimed;

	curr = 0;
	trimed = NULL;
	str = dollar(str);
	while (str[curr])
	{
		if (str[curr] == DOUBLE_QUOTE || str[curr] == SINGLE_QUOTE)
			removed = clean_quote_with_type(str, &curr, str[curr]);
		else
			removed = get_str(str, &curr);
		push_new_str(&trimed, removed);
	}
	free(str);
	return (trimed);
}

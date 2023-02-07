/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btekinli <btekinli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:53:28 by btekinli          #+#    #+#             */
/*   Updated: 2022/10/12 22:13:30 by btekinli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_word_count(char const *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (!str || !ft_strlen(str))
		return (0);
	if (str[i] != c)
	{
		i++;
		words++;
	}
	while (str[i] && ft_strlen(str) > 0)
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
		{
			words++;
		}
		i++;
	}
	return (words);
}

char	*ft_split_word(char const *str, char c)
{
	char			*word;
	unsigned int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	word = (char *)malloc(i + 1);
	i = 0;
	while (str[i] != c && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**free_list(char **result)
{
	unsigned int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		index;

	if (!str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_word_count(str, c) + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
			result[index] = ft_split_word(str, c);
			if (!(result[index]))
				return (free_list(result));
			while (*str != c && *str)
				str++;
			index++;
		}
		else
			str++;
	}
	result[index] = NULL;
	return (result);
}

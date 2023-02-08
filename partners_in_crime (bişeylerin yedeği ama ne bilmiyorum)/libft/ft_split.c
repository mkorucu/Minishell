/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:26:01 by bkeklik           #+#    #+#             */
/*   Updated: 2022/06/27 19:32:34 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordslength(char const *s, char c)
{
	size_t	letter;

	letter = 0;
	while (s[letter] && s[letter] != c)
		letter++;
	return (letter);
}

static size_t	words(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	len = words(s, c);
	new = malloc(sizeof(char *) * len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*s == c && *s != 0)
			s++;
		new[i] = malloc(sizeof(char) * wordslength(s, c) + 1);
		j = 0;
		while (*s != c && *s != 0)
			new[i][j++] = *s++;
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}

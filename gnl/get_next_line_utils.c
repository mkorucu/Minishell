/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:30:30 by bkeklik           #+#    #+#             */
/*   Updated: 2022/07/25 15:30:53 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	j;
	size_t	i;
	char	*collect;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	collect = malloc(sizeof(char) * ((ft_strlen(str)) + ft_strlen(buff) + 1));
	if (collect == NULL)
		return (NULL);
	j = -1;
	i = 0;
	if (str)
		while (str[++j] != '\0')
			collect[j] = str[j];
	while (buff[i] != '\0')
		collect[j++] = buff[i++];
	collect[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free (str);
	return (collect);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[ft_strlen(str)]);
		i++;
	}
	return (0);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_str(char *str)
{
	int		i;
	int		j;
	char	*pstr;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	pstr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!pstr)
		return (NULL);
	i++;
	while (str[i])
		pstr[j++] = str[i++];
	pstr[j] = '\0';
	free (str);
	return (pstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:53:23 by bkeklik           #+#    #+#             */
/*   Updated: 2022/07/26 18:54:42 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_buff(int fd, char *str)
{
	int		rd;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read_buff(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_line(str[fd]);
	str[fd] = ft_str(str[fd]);
	return (line);
}

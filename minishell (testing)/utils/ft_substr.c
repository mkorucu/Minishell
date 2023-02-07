/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btekinli <btekinli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:21:34 by btekinli          #+#    #+#             */
/*   Updated: 2022/10/12 22:14:02 by btekinli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	srclen;

	if (str == 0)
		return ((char *)str);
	srclen = ft_strlen(str);
	if (srclen <= len)
		len = srclen;
	if (start >= srclen)
	{
		dest = malloc(1);
		*dest = 0;
		return (dest);
	}
	else
	{
		str += start;
		dest = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (!dest)
		return (NULL);
	dest = ft_memcpy(dest, str, len);
	dest[len] = '\0';
	return (dest);
}

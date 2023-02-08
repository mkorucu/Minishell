/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:10:12 by bkeklik           #+#    #+#             */
/*   Updated: 2022/06/25 15:44:49 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	hay;
	size_t	need;

	hay = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[hay] != 0 && hay < n)
	{
		need = 0;
		while (haystack[hay + need] == needle[need]
			&& needle[need] && need + hay < n)
			need++;
		if (need == ft_strlen(needle))
			return ((char *)&haystack[hay]);
		hay++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:16:40 by bkeklik           #+#    #+#             */
/*   Updated: 2022/06/24 20:39:25 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void	*src, size_t len)
{
	char	*d;
	char	*s;

	if (dst == src || len == 0)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			len--;
			d[len] = s[len];
		}
	}
	return (dst);
}

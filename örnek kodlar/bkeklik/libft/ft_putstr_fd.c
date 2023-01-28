/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:00:42 by okarakel          #+#    #+#             */
/*   Updated: 2023/01/23 20:34:00 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		c += ft_putchar_fd(s[i++], fd);
	return (c);
}

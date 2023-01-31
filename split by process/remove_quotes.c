/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:43:26 by mkorucu           #+#    #+#             */
/*   Updated: 2023/01/31 12:29:46 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

char	*remove_quotes(char *str)
{
	int		i;
	char	*removed;
	char	*trimed;

	i = 0;
	trimed = NULL;
	str = dollar(str);
	
	
}
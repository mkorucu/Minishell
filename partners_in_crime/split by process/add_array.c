/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:04:36 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/01 15:18:03 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

char	**add_array(char **arr, char *new_str)
{
	int		i;
	int		len;
	char	**new_arr;

	len = 0;
	i = -1;
	while (arr && arr[len])
		len++;
	new_arr = ft_calloc(sizeof(char *), len + 2);
	while (++i < len)
		new_arr[i] = arr[i];
	new_arr[i] = new_str;
	free(arr);
	return (new_arr);
}
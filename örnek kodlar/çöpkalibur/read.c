/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:05:42 by bkeklik           #+#    #+#             */
/*   Updated: 2022/12/23 11:09:33 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_line()
{
	write(1, BLUE, 5);
	hack.read1 = readline("minishell ");
	if (!(ft_strncmp(hack.read1, "", 1)))
		read_line();
}
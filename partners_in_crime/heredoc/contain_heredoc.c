/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contain_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:43:13 by mkorucu           #+#    #+#             */
/*   Updated: 2023/02/06 18:49:53 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	contain_heredoc(t_process	*process)
{
	int	i;
	
	i = 0;
	while(process->redirects[i])
	{
		if (operator_check(process->redirects[i]) == HERE_DOC)
			return (1);
		i++;
	}
	return (0);
}
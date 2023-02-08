/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:08:25 by btekinli          #+#    #+#             */
/*   Updated: 2023/02/08 11:30:16 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**push_array(char **arr, char *new_str)
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

void	init_process(t_process **new_process)
{
	*new_process = ft_calloc(sizeof(t_process), 1);
	pipe((*new_process)->fd);
	(*new_process)->pid = -1;
	(*new_process)->execute = ft_calloc(sizeof(char *), 1);
	(*new_process)->redirects = ft_calloc(sizeof(char *), 1);
	(*new_process)->prev = NULL;
	(*new_process)->next = NULL;
}

void	add_process(t_process **list, t_process *new_process)
{
	t_process	*curr;

	curr = *list;
	if (!curr)
		*list = new_process;
	else
	{	
		while (curr->next)
			curr = curr->next;
		curr->next = new_process;
		new_process->prev = curr;
	}
}

int	list_arguments(t_token **chain, t_process *process)
{
	char	*str;

	if ((*chain)->type == STRING)
	{
		str = remove_quotes((*chain)->str); //DAHA YAZMADIM
		process->execute = push_array(process->execute, str);
	}
	else
	{
		str = remove_quotes((*chain)->str);
		process->redirects = push_array(process->redirects, str);
		*chain = (*chain)->next;
		if (!(*chain) || (*chain)->type != STRING)
		{
			if (!(chain))
				chain_error(0);
			else
				chain_error((*chain)->type);
			free_chain();
			return (0);
		}
		str = remove_quotes((*chain)->str);
		process->redirects = push_array(process->redirects, str);
	}
	return (1);
}

int	listing_process(void)
{
	t_token		*c_curr;
	t_process	*p_curr;

	c_curr = g_ms.token;

	while (c_curr)
	{
		if (c_curr->type == PIPE || c_curr->prev == NULL)
		{
			if (c_curr->type == PIPE)
				c_curr = c_curr->next;
			init_process(&p_curr);
			add_process(&g_ms.process, p_curr);
			g_ms.process_count++;
		}
		if (!c_curr)
			break ;
		if (!list_arguments(&c_curr, p_curr))
			return (FALSE);
		if (c_curr)
			c_curr = c_curr->next;
	}
	free_chain();
	return (TRUE);
}

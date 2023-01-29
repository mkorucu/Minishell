/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:44:53 by bkeklik           #+#    #+#             */
/*   Updated: 2023/01/29 21:30:57 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	start(char *input)
{
	if (*input)
		return ;
	crime.chain = NULL;
	crime.process
}

int	main(int ac, char **av, char **env)
{
	char	*input2;
	char	*input;
	crime.ac = ac;
	init_app();
	init_env(env);
	init_path();
	while (av && ac)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\033[32m", 5);
		input2 = ft_strjoin(g_ms.user," minishell_> ");
		input = readline(input2);
		write(1, "\033[0m", 4);
		handle_exit(input);
		if(crime.ignore)
		if (*input)
			start(input);
		free(input);
		free(input2);
	}
	exit(errno);
}
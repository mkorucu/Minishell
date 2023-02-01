/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:44:53 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/01 11:03:16 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start(char *input)
{
	if (*input)
		return ;
	g_crime.chain = NULL;
	g_crime.process = ;
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	*input2;
	char	*color;

	commit_an_offense(env);
	init(env);
	while (av && ac)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\033[32m", 5);
		input2 = ft_strjoin(g_crime.user, " minishell_> ");
		color = ft_strjoin(MAGENTA, input2);
		input = readline(color);
		write(1, "\033[0m", 4);
		handle_exit(input);
		if (g_crime.ignore)
		if (*input)
			start(input);
		free(input);
		free(input2);
		free(color);
	}
	exit(errno);
}

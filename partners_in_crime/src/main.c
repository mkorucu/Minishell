/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:44:53 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/01 13:49:37 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start(char *input)
{
	if (*input)
		return ;
	g_crime.chain = NULL;
	g_crime.process = NULL;
}

char	*prompt(void)
{
	char	*str;
	char	*color;

	str = ft_strjoin(g_crime.user, " minishell_> ");
	color = ft_strjoin(MAGENTA, str);
	free (str);
	return (color);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	*color;

	commit_an_offense();
	init(env);
	while (av && ac)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		color = prompt();
		input = readline(color);
		handle_exit(input);
		//if (g_crime.ignore) // burası
		start(input); //Burası
		free(input);
		free(color);
	}
	exit(errno);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:44:53 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/08 20:07:44 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	commit_an_offense(char **env)
{
	errno = 0;
	g_crime.paths = NULL;
	g_crime.parent_pid = getpid();
	g_crime.env = env;
	g_crime.user = get_env("USER");
	set_paths();
}

void	start(char *input)
{
	if (!*input)
		return ;
	g_crime.chain = NULL;
	g_crime.process = NULL;
	g_crime.process_count = 0;
	listing(input);
	if (!listing_process())
		return ;
	start_cmd();
}

char	*prompt(void)
{
	char	*str;
	char	*color;

	str = ft_strjoin(g_crime.user, " minishell % ");
	color = ft_strjoin(MAGENTA, str);
	free (str);
	return (color);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	*prompter;

	commit_an_offense(env);
	while (av && ac)
	{
		signal(SIGINT, &handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		g_crime.fail = 0;
		prompter = prompt();
		input = readline(prompter);
		write(1, DEFAULT, 10);
		handle_exit(input);
		if (g_crime.fail)
		{
			free(input);
			input = malloc(1);
		}
		start(input);
		add_history(input);
		free(input);
		free(prompter);
		system("leaks minishell");
	}
	exit(errno);
}

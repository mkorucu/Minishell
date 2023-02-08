/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:23 by btekinli          #+#    #+#             */
/*   Updated: 2023/02/08 14:12:56 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_ms;

void	init_app(char **env)
{
	errno = 0;
	g_ms.paths = NULL;
	g_ms.parent_pid = getpid();
	g_ms.env = env;
	g_ms.user = get_env("USER");
	set_paths();
}

void	start(char *input)
{
	if (!*input)
		return ;
	g_ms.token = NULL;
	g_ms.process = NULL;
	g_ms.process_count = 0;
	listing(input);
	if (!listing_process())
		return ;
	start_cmd();
	free_process();
}

char	*prompt(void)
{
	char	*str;
	char	*color;

	str = ft_strjoin(g_ms.user, " minishell % ");
	color = ft_strjoin(MAGENTA, str);
	free (str);
	return (color);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	*prompter;
	
	init_app(env);
	while (ac && av)
	{
		signal(SIGINT, &handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		g_ms.ignore = FALSE;
		prompter = prompt();	
		input = readline(prompter);
		write(1, DEFAULT, 10);
		ctrl_d(input);
		if (g_ms.ignore)
		{
			free(input);
			input = malloc(1);
		}
		start(input);
		add_history(input);
		free(input);
		free(prompter);
	}
	exit(errno);
}

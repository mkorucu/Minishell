/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:23 by fkaratay          #+#    #+#             */
/*   Updated: 2023/01/29 18:03:50 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_ms;

void	init_app(char **env)
{
	int	i;
	int	j;
	
	i = 0;
	(void)env;
	errno = 0;
	g_ms.paths = NULL;
	g_ms.parent_pid = getpid();
	while(env[i])
	{
		if (!ft_strncmp(env[i], "USER=", 5))
		{
			j = 5;
			while(env[i][j] != '\0')
				j++;
			g_ms.user = ft_calloc(sizeof(char), j - 4);
			g_ms.user = ft_strdup(&env[i][5]);
		}
		i++;
	}
}

void	init_shell(char *input)
{
	(void)input;
	g_ms.token = NULL;
	g_ms.process = NULL;
	g_ms.process_count = 0;
}
void	ctrl_c(int sig)
{
	(void)sig;
	g_ms.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit(errno);
	}
}


int	main(int ac, char **av, char **env)
{
	char	*input2;
	char *input;
	init_app(env);
	set_env(env);
	set_paths();
	while (ac && av)
	{
		g_ms.ignore = FALSE;
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\033[32m", 5);
		input2 = ft_strjoin(g_ms.user, " minishell > ");
		input = readline(input2);
		write(1, "\033[0m", 4);
		ctrl_d(input);
		if (g_ms.ignore)
		{
			free(input);
			input = malloc(1);
		}
		if (*input)
		{
			init_shell(input);
			tokenize(input);
			if (!lexer())
				continue;
			start_cmd();
			free_process();
			add_history(input);
		}
		free(input);
	}
	exit(errno);
}

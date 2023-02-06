/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:23 by fkaratay          #+#    #+#             */
/*   Updated: 2023/02/06 20:14:31 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_ms;

void	init_app(char **env)
{
	(void)env;
	errno = 0;
	g_ms.paths = NULL;
	g_ms.parent_pid = getpid();
}

void	init_shell(char *input)
{
	(void)input;
	if (!(*input))
		return ;
	g_ms.token = NULL;
	g_ms.process = NULL;
	g_ms.process_count = 0;
	tokenize(input);
	if (!lexer())
		return ;
	printf("%s\n%s\n",g_ms.process->execute[0],g_ms.process->execute[1]);
	start_cmd();
	free_process();
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
	char	*input;
	char	*color;

	init_app(env);
	g_ms.env = env;
	g_ms.user = get_env("USER");
	set_paths();
	while (ac && av)
	{
		g_ms.ignore = FALSE;
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\033[32m", 5);
		input2 = ft_strjoin(g_ms.user, " minishell_> ");
		color = ft_strjoin(MAGENTA, input2);
		write(1, "\033[0m", 4);
		input = readline(color);
		ctrl_d(input);
		if (g_ms.ignore)
		{
			free(input);
			input = malloc(1);
		}
		if (*input)
		{
			init_shell(input);
			add_history(input);
		}
		free(input);
	}
	exit(errno);
}


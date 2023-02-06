/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:23 by fkaratay          #+#    #+#             */
/*   Updated: 2023/02/06 20:39:00 by bkeklik          ###   ########.fr       */
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
int	str_check(char *str, char type)
{
	int i = 0, count = 0;
	while(str[i])
	{
		if(str[i] == type)
			count++;
		i++;
	}
	if (count % 2 == 1)
		return (1);
	return (0);
}
int	main(int ac, char **av, char **env)
{
	char	*input2;
	char	*input;
	char	*color;
	int i = 0;
	int j = 0;
	init_app(env);
	set_env(env);
	set_paths();
	while (ac && av)
	{
		g_ms.ignore = FALSE;
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\033[32m", 5);
		input2 = ft_strjoin(g_ms.user, " minishell_> ");
		color = ft_strjoin(MAGENTA, input2);
		
		while(color[i])
		{
			if(color[i] == '"')
			{
				if(str_check(color, '"'))
					j = 2;		
			}
			else{
				if(str_check(color, '"'))
					j = 2;	
			}
			i++;
		}
		if(!(j==2))
		{
			while (1)
			{	
				int len = ft_strlen2(av);
				signal(SIGINT, &ctrl_c);
				input = readline(">");
				if (!input || ft_strcmp(av[len-1], color) || g_ms.ignore)
				{
					free(input);
					errno = 1;
					perror("minishell");
				}
			}
		}
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


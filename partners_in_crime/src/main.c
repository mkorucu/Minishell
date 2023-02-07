/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:44:53 by bkeklik           #+#    #+#             */
/*   Updated: 2023/02/07 11:25:14 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	handle_sigint(int sig)  //ctrl_c
{
	if (sig == SIGINT)
	{
		g_crime.fail = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		write(1, "\033[A", 3);
	}
}

void	handle_exit(char *str)
{
	if (!str)
	{
		printf("exit\n");
		exit(errno);
	}
}

void	start(char *input)
{
	if (*input)
		return ;
	g_crime.chain = NULL;
	g_crime.process = NULL;
	g_crime.process_count = 0;
	listing(input);
	if(!listing_process())
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
	char	*color;

	commit_an_offense(env); //init(env)
	while (av && ac)
	{
		signal(SIGINT, &handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		color = prompt();
		input = readline(color);
		write(1,DEFAULT, 5);
		handle_exit(input);
		if (g_crime.fail)
		{
			free(input);
			input = malloc(1);
		}
		start(input); //Burası
		add_history(input);
		free(input);
		free(color);
	}
	exit(errno);
}

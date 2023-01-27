#include "../lib/minishell.h"

t_data hack;

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		hack.fail = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
}
}

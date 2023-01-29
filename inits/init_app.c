#include "../lib/minishell.h"

void	init_app(void)
{
	errno = 0;
	crime.paths = NULL;
	crime.parent_pid = getpid();
}
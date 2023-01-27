#include "../lib/minishell.h"


int main(int ac, char **av, char **env)
{
    char	*str;
    
	hack.ac = ac;
    while(av && ac)
    {
        signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		str = get_prompt();
    }
}
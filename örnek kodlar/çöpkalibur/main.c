#include "minishell.h"

t_data	hack;

static	char *get_home()
{
	char	*temp;
	char	*pwd;
	char	*home1;

	pwd = getcwd(NULL, 0);
	if(!pwd) 
		pwd = ft_strdup("∅ ");
	home1 = ("HOME", hack.envp, 4);
	if (home1 && home1[0] && ft_strnstr(pwd, home1, ft_strlen(pwd)))
	{
		temp = pwd;
		pwd = ft_strjoin("~", &pwd[ft_strlen(pwd)]);
		free(temp);
	}
	free(home1);
	
}

char	*take_minishell(char **envp)
{
	char	*user;
	char	*temp;
	char	*home;

	user = NULL;
	exec_custom(&user, "/usr/bin/whoami","whoami", envp);
	temp = ft_strjoin(user, "@minishell");
	free(user);
	home = get_home();
	
	
}

int	main(int argc, char **argv, char **envp)
{
	char	*read_str;
	hack.ac = argc;
	hack.av = argv;
	env_init(envp);
	while(argv && argc)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\033[32m", 5);
		read_str = read_line("minishell_> ");
		write(1, "\033[0m", 4);
	}
}

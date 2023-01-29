/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:28:51 by bkeklik           #+#    #+#             */
/*   Updated: 2023/01/21 03:30:26 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>


#define	RESET	"\033[0m"
#define	GREEN	"\033[32m"
#define	YELLOW	"\033[33m"
#define	BLUE	"\033[34m"
#define	RED		"\033[31m"

enum tokentype
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	DBLREDIR_IN,
	DBLREDIR_OUT	
};

typedef struct s_token
{
	enum tokentype	type;
	char			*str;
	struct s_token	*next;
	struct s_token	*prev;
} t_token;

typedef struct s_data
{
	int		ac;
	int		parent_pid;
	int		process_count;
	char	**av;
	char	**env;
	char	**paths;
	char	*read1;
	char	**read2;
	t_token	*token;
}		t_data;

extern t_data hack;
void	env_init(char *env);
void	tokenize(char *cmd);

void	ft_free_array(char **str)

#endif
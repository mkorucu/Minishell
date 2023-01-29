#include "../minishell.h"

int ft_isspecified(char *str)
{
    if (!str)
        return (0);
    else if (str[0] == '>' && str[1] == '>')
        return (DBLREDIR_OUT);
    else if (str[0] == '<' && str[1] == '<')
        return (DBLREDIR_IN);
    else if (str[0] == '<')
        return (REDIR_IN);
    else if (str[0] == '>')
        return (REDIR_OUT);
    else if (str[0] == '|')
        return (PIPE);
    else
        return (0);
}

int string_token_adder(char *word)
{
    word = 0;
    return 0;
}

int token_creator(t_token **token, char *s, int type)
{
    t_token *t;
    t_token *temp;

    t = *token;
    while (t->next)
        t = t->next;
    
    temp = t;
    t = t->next;
    t = malloc(sizeof(t_token));
    t->type = type;
    t->str = ft_strdup(s);
    t->next = NULL;
    t->prev = temp;
    return (ft_strlen(s));
}

int token_adder(int type, char *word)
{
    if (word)
        return (string_token_adder(word));
    if (type == REDIR_IN)
        return (token_creator(&hack.token, "<", type));
    if (type == REDIR_OUT)
        return (token_creator(&hack.token, ">", type));
    if (type == DBLREDIR_IN)
        return (token_creator(&hack.token, "<<", type));
    if (type == DBLREDIR_OUT)
        return (token_creator(&hack.token, ">>", type));
    if (type == PIPE)
        return (token_creator(&hack.token, "|", type));
    return (0);
}

void    tokenize(char *cmd)
{
    while (*cmd)
    {
        if (*cmd== ' ' || *cmd == '\t')
            cmd++;
        cmd += token_adder(ft_isspecified(cmd), NULL);
    }

}
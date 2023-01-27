/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:21:43 by bkeklik           #+#    #+#             */
/*   Updated: 2022/07/01 18:40:19 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstnew;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lstnew = *lst;
	lstnew = ft_lstlast(lstnew);
	lstnew->next = new;
}

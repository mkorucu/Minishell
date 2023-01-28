/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:10:47 by bkeklik           #+#    #+#             */
/*   Updated: 2022/07/26 19:13:48 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_read_buff(int fd, char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buff);
char	*ft_strchr(char *str, int c);
char	*ft_line(char *str);
char	*ft_str(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:31:26 by bkeklik           #+#    #+#             */
/*   Updated: 2022/07/25 15:31:47 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buff);
char	*ft_strchr(char *str, int c);
char	*ft_line(char *str);
char	*ft_str(char *str);
char	*ft_read_buff(int fd, char *str);
char	*get_next_line(int fd);

#endif
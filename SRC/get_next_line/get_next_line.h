/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 13:56:35 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/01/13 13:54:25 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../../so_long.h"
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_substr(char const *str, unsigned int start, size_t len);

char	*ft_strjoin(char *str1, char *str2);

char	*ft_strdup(const char *str);

char	*ft_strchr(char *str, int c);

int		get_next_line(int fd, char **line);

size_t	ft_strlen(char const *str);

#endif

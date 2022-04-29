/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 13:56:35 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/01/16 15:30:22 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*strjoin;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	strjoin = (char *)malloc(sizeof(char) * \
		(ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!strjoin)
		return (NULL);
	while (str1[i] != '\0')
	{
		strjoin[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		strjoin[i + j] = str2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	free(str1);
	return (strjoin);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*strdup;

	i = 0;
	strdup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!strdup)
		return (NULL);
	while (str[i] != '\0')
	{
		strdup[i] = str[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

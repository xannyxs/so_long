/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:43:42 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 17:44:53 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] != 0 && str2[i] != 0) && (str1[i] == str2[i]))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

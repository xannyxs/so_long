/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 15:08:26 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 15:08:28 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*str2;
	int		i;

	str2 = (char *)str;
	i = 0;
	while (*str2 != '\0')
	{
		str2++;
		i++;
	}
	while (i >= 0)
	{
		if (*str2 == c)
			return (str2);
		str2--;
		i--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:52:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:52:50 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned long	i;
	char			*s;
	char			c2;

	s = (char *)str;
	c2 = (char)c;
	i = 0;
	while (n)
	{
		n--;
		if (s[i] == c2)
			return (s + i);
		i++;
	}
	return (NULL);
}

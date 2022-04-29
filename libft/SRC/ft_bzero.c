/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:48:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 17:01:53 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned long	i;
	char			*s;

	s = (char *) str;
	i = 0;
	while (n > i)
	{
		s[i] = 0;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:58:13 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 17:02:47 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	if (src != NULL || dest != NULL)
	{
		while (n)
		{
			n--;
			*d = *s;
			d++;
			s++;
		}
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:57:43 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 17:03:04 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ds;
	const unsigned char	*sr;
	size_t				i;

	sr = (const unsigned char *) src;
	ds = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		if (sr[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}

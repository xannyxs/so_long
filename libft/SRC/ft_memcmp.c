/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:57:55 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 17:01:17 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ucs1;
	const unsigned char	*ucs2;

	ucs1 = (const unsigned char *)s1;
	ucs2 = (const unsigned char *)s2;
	if (n == 0 || s1 == s2)
		return (0);
	while (n)
	{
		n--;
		if (*ucs1 != *ucs2)
			return ((unsigned char) *ucs1 - (unsigned char) *ucs2);
		if (n)
		{
			ucs1++;
			ucs2++;
		}
	}
	return ((unsigned char) *ucs1 - (unsigned char) *ucs2);
}

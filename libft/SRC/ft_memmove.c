/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:58:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 18:46:31 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*str_dest;
	char	*str_src;

	str_dest = (char *)dest;
	str_src = (char *)src;
	if (dest != NULL || src != NULL)
	{
		if (str_dest > str_src)
		{
			while (len)
			{
				len--;
				str_dest[len] = str_src[len];
			}
		}
		else
		{
			while (len)
			{
				len--;
				*str_dest = *str_src;
				str_dest++;
				str_src++;
			}
		}
	}
	return (dest);
}

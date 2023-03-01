/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:58:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/07 17:41:38 by xvoorvaa      ########   odam.nl         */
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
			while (len--)
			{
				str_dest[len] = str_src[len];
			}
		}
		else
		{
			while (len--)
			{
				*str_dest = *str_src;
				str_dest++;
				str_src++;
			}
		}
	}
	return (dest);
}

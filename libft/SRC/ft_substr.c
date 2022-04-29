/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:51:17 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:51:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t			i;
	size_t			slen;
	char			*substr;

	i = 0;
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (str[i] && i < len && slen > start)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

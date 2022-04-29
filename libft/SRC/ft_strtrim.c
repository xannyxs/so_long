/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:47:57 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:47:59 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strrchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strrchr(set, s1[i]))
		i--;
	ptr = ft_substr((char *)s1, 0, i + 1);
	return (ptr);
}

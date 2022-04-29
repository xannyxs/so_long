/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:55:07 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/01/12 16:30:50 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t n)
{
	void	*result;
	size_t	total;

	total = nitems * n;
	if (nitems == 0 || n == 0)
	{
		n = 1;
		nitems = 1;
	}
	result = malloc(n * nitems);
	if (!result)
		return (NULL);
	ft_bzero(result, total);
	return (result);
}

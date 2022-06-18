/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 21:29:56 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/18 18:12:39 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include <stdlib.h>

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		fatal_perror("malloc");
	return (ptr);
}

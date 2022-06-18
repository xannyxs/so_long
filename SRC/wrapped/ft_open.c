/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_open.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 16:04:15 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 18:13:43 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include <unistd.h>
#include <fcntl.h>

int	ft_open(char *cub_file)
{
	int	fd;

	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
		fatal_perror(cub_file);
	return (fd);
}

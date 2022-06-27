/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 11:18:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/27 11:52:49 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#include <unistd.h>

void	print_movement(t_vars *vars)
{
	vars->moves++;
	write(STDOUT_FILENO, "MOVES: ", 7);
	ft_putnbr_fd(vars->moves, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
}

void	reset_image(mlx_image_t *img)
{
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 20:30:14 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/18 22:07:11 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error.h"
#include "libft.h"

#include <stdbool.h>

/*
    free_pointer: to free the pointer (duh)
    file_utils: Checks if file is OK
    read_file: Reads the file with GNL and puts the results in a linkedlist.
    check_valid_file: Checks if given file is .ber
*/

static bool	is_ber_extension(char *argv)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv, '.');
	if (str == NULL)
		fatal_perror("malloc");
	while (str[i] != NULL)
		i++;
	i--;
	if (ft_strcmp(str[i], "ber") == 0)
	{
		ft_free_array(str);
		return (true);
	}
	ft_free_array(str);
	non_fatal_error(NONVALID_FILE);
	return (false);
}

bool	is_ber_file_valid(char *ber_file, t_vars *vars)
{
	if (is_ber_extension(ber_file) == false)
		return (false);
	if (read_file(ber_file, vars))
		return (false);
	if (check_map(&vars->map_data))
		return (false);
	return (true);
}

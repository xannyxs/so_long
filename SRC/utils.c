/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 20:30:14 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/29 13:02:16 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#include <unistd.h>

/*
    free_pointer: to free the pointer (duh)
    file_utils: Checks if file is OK
    read_file: Reads the file with GNL and puts the results in a linkedlist.
    check_valid_file: Checks if given file is .ber
*/

int	error_message(void)
{
	write(STDERR_FILENO, "Error\n", 7);
	write(STDERR_FILENO, "An error has occurred\n", 23);
	return (-1);
}

int	file_utils(char *argv[], t_node **map, t_vars *vars)
{
	int	ret;

	ret = check_valid_file(argv);
	if (ret != 0)
		return (-1);
	ret = read_file(argv, map, vars);
	if (ret != 0)
		return (-1);
	return (0);
}

int	read_file(char *argv[], t_node **map, t_vars *vars)
{
	int		fd;
	char	*line;

	line = NULL;
	vars->height = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	if (get_line(fd, line, map, vars) != 0)
		return (-1);
	if (check_map(vars, *map) != 0)
		return (-1);
	close(fd);
	return (0);
}

int	check_valid_file(char *argv[])
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv[1], '.');
	if (str == NULL)
		return (-1);
	while (str[i] != NULL)
		i++;
	i--;
	if (ft_strcmp(str[i], "ber") == 0)
	{
		ft_free_array(str);
		return (0);
	}
	ft_free_array(str);
	return (-1);
}

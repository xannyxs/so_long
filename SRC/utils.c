/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 20:30:14 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/01 17:39:02 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
    free_pointer: to free the pointer (duh)
    file_utils: Checks if file is OK
    read_file: Reads the file with GNL and puts the results in a linkedlist.
    check_valid_file: Checks if given file is .ber
*/

int	error_message(void)
{
	write(2, "Error\n", 6);
	write(2, "An error has occurred\n", 22);
	return (-1);
}

void	free_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
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
		free_pointer(str);
		return (0);
	}
	free_pointer(str);
	return (-1);
}

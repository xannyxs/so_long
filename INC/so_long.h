/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 16:09:01 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 23:55:01 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

# define SUCCES 0
# define ERROR 1

typedef struct	s_node
{
	char			*data;
	struct s_node	*next;
}	t_node;

typedef struct	s_map
{
	unsigned int	width;
	unsigned int	height;
	char			**world_map;
}	t_map;

typedef struct	s_vars
{
	int				player_x;
	int				player_y;
	int				collectables;
	int				enter_exit;
	int				ping;
	int				moves;
	int				p_check;
	mlx_t			*mlx;
	mlx_image_t		*screen;
	t_map			map_data;
}	t_vars;

/*
	CHECK_MAP
*/

bool			is_ber_file_valid(char *ber_file, t_vars *vars);

int				check_map(t_map *map_data);

int				check_exit(char *world_map[]);

int				check_player(char *world_map[]);

int				check_collectables(char *world_map[]);

int				check_wall(char *world_map[]);

int				check_unknown(char *world_map[]);

/*
	PLACE OBJ
*/

void			place_objects(void *param);

void			place_player(t_vars *vars);

void			place_cherry(t_vars *vars);

void			place_exit(t_vars *vars);

void			place_wall(t_vars *vars);

void			place_background(t_vars *vars);

/*
	MOVEMENT
*/

void			to_left(t_vars *vars);

void			to_right(t_vars *vars);

void			to_up(t_vars *vars);

void			to_down(t_vars *vars);

/*
	UTILS
*/

int				check_valid_file(char *argv[]);

int				read_file(char *cub_file, t_vars *vars);

int				get_next_line(int fd, char **line);

int				get_line(int fd, char *line, t_node **map, t_vars *vars);

int				check_valid_file(char *argv[]);

void			find_player(t_vars *vars, char *world_map[]);

//void			animation_player(t_vars *vars, t_img *sprite);

/*
	LINKED LIST
*/

void			ft_free_list(t_node **head);

void			new_node(t_node **head, char *data);

int				insert_to_list(t_vars *vars, t_node **map, char *line);

int				ft_lstlen(t_node *head);

/*
	WRAPPED
*/

void			*ft_malloc(size_t size);

int				ft_open(char *cub_file);

#endif

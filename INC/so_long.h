/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 16:09:01 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:15:39 by xander        ########   odam.nl         */
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
	int			img_height;
	int			img_width;
	int			collectables;
	int			enter_exit;
	int			buffer;
	int			ping;
	int			moves;
	int			p_check;
	mlx_t		*mlx;
	void		*win;
	void		*img;
	t_map		map_data;
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

//void			draw_sprite(t_img *img, t_img *sprite, int x, int y);

//void			place_all_objects(t_vars vars, t_node *map);

//void			place_player(t_vars *vars, t_img *img, t_node *map);

//void			place_cherry(t_vars *vars, t_img *img, t_node *map);

//void			place_exit(t_vars *vars, t_img *img, t_node *map);

//void			place_wall(t_vars *vars, t_img *img, t_node *map);

//void			place_background(t_vars *vars, t_img *img, t_node *map);

/*
	MOVEMENT
*/

int				to_left(t_vars *vars);

int				to_right(t_vars *vars);

int				to_up(t_vars *vars);

int				to_down(t_vars *vars);

int				swap_list_left(t_vars *vars, t_node *new_list);

int				swap_list_right(t_vars *vars, t_node *new_list);

int				swap_list_up(t_vars *vars, t_node *new_list, t_node *down_node);

int				swap_list_down(t_vars *vars, t_node *new_list, \
					t_node *down_node);

/*
	UTILS
*/

int				check_valid_file(char *argv[]);

int				read_file(char *cub_file, t_vars *vars);

int				get_next_line(int fd, char **line);

int				get_line(int fd, char *line, t_node **map, t_vars *vars);

int				check_valid_file(char *argv[]);

//void			animation_player(t_vars *vars, t_img *sprite);

/*
	LINKED LIST
*/

void			ft_free_list(t_node **head);

void			new_node(t_node **head, char *data);

int				insert_to_list(t_vars *vars, t_node **map, char *line);

int				ft_lstlen(t_node *head);

/*
	MY MLX
*/

//void			my_mlx_pixel_put(t_img *img, int x, int y, int colour);

//unsigned int	my_mlx_colour_put(t_img *sprite, int x, int y);

/*
	WRAPPED
*/

void			*ft_malloc(size_t size);

int				ft_open(char *cub_file);

#endif

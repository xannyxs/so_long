/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 16:09:01 by xander        #+#    #+#                 */
/*   Updated: 2022/01/31 18:41:06 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_node {
	int				number;
	struct s_node	*next;
}				t_node;

typedef struct s_vars {
	int			height;
	int			width;
	int			img_height;
	int			img_width;
	int			collectables;
	int			enter_exit;
	int			buffer;
	int			ping;
	int			moves;
	int			p_check;
	void		*mlx;
	void		*win;
	void		*img;
	t_node		*map;
}				t_vars;

enum e_KEYS{
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};

/*
	SO_LONG
*/

int				check_exit(t_node *map);

int				check_player(t_node *map);

int				check_collectables(t_node *map);

int				check_wall(t_vars *vars, t_node *map);

int				check_unknown(t_node *map);

int				main(int argc, char *argv[]);

/*
	PLACE OBJ
*/

void			draw_sprite(t_img *img, t_img *sprite, int x, int y);

void			place_all_objects(t_vars vars, t_node *map);

void			place_player(t_vars *vars, t_img *img, t_node *map);

void			place_cherry(t_vars *vars, t_img *img, t_node *map);

void			place_exit(t_vars *vars, t_img *img, t_node *map);

void			place_wall(t_vars *vars, t_img *img, t_node *map);

void			place_background(t_vars *vars, t_img *img, t_node *map);

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

void			free_pointer(char **str);

int				check_valid_file(char *argv[]);

int				read_file(char *argv[], t_node **map, t_vars *vars);

int				get_next_line(int fd, char **line);

int				file_utils(char *argv[], t_node **map, t_vars *vars);

int				get_line(int fd, char *line, t_node **map, t_vars *vars);

int				check_valid_file(char *argv[]);

int				check_map(t_vars *vars, t_node *map);

int				error_message(void);

void			animation_player(t_vars *vars, t_img *sprite);

/*
	LINKED LIST
*/

int				free_list(t_node **head);

int				new_node(t_node **head, int value);

int				insert_to_list(t_vars *vars, t_node **map, char *line);

int				ft_lstlen(t_node *head);

/*
	LIBFT
*/
void			ft_bzero(void *str, size_t n);

char			**ft_split(char const *s, char c);

size_t			ft_strlen(char const *str);

char			*ft_substr(char const *str, unsigned int start, size_t len);

void			*ft_calloc(size_t nitems, size_t n);

int				ft_strcmp(const char *str1, const char *str2);

void			ft_putnbr_fd(int n, int fd);

/*
	MY MLX
*/

void			my_mlx_pixel_put(t_img *img, int x, int y, int colour);

unsigned int	my_mlx_colour_put(t_img *sprite, int x, int y);

#endif

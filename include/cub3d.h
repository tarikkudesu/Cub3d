/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:13:44 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 19:38:55 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <mlx.h>
# include "struct.h"
# include "macros.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*--------------------parser-------------------*/
int 	get_map_cord(t_cub3d *cub);
int 	file_parse(t_cub3d *cub, char *file);
void	line_add_back(t_line **line, t_line *node);
void	get_min_max(t_line *line, int *min, int *max);
t_line	*new_line(char *line, int off, int last);
int 	fill_one(t_cub3d *cub, t_map **map, t_line *line, int min);

//bools
int 	is_num(char c);
int 	empty(char *line);
int 	all_num(char *str);
int 	all_ones(char *line);
int 	valid_char(char line);
int 	valid_component(t_cub3d *cub, char *line);
int 	wall_exist(int front, int less, t_line *c_line, t_line *p_line);

//mini_libft
char	*get_next_line(int fd);
int 	ft_atoi(const char *s);
int 	ft_strlen(const char *s);
int 	ft_strcmp(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_gl(char	**buf);
int		read_swap(char **buf, int fd, int *check);
char	*strjoin(char *s1, char *s2);
int		get_index(char *s);
int		exist(char *s);
void	ft_cpy(char *dst, char *src, unsigned int len);
void	change(char **s1, char **s2);

void	*talloc(size_t __size);
char	*ft_strdup(const char *s1);
void	putendl_fd(char *s, int fd);

/* FUNCTIONS */
void	image_addback(t_imgcontainer **lst, t_imgcontainer *new);
t_heap	*image_new(void *content);
void	heap_addback(t_heap **lst, t_heap *new);
t_heap	*heap_new(void *content);
void	leaks(void);
t_cub3d			*get_cub(t_cub3d *cub);
bool			set_sprite_data(t_cub3d *cub);
void			set_distance(t_cub3d *cub);
void			initialize_data(t_cub3d *cub);
void			open_doors(t_cub3d *cub);
void			put_sprites(t_cub3d *cub, int *z_coor);
void			dda(t_cub3d *cub, t_ray *ray);
void			render_column(t_vect *start, t_vect *end, t_ray *ray, t_cub3d *cub);
void			put_rays(t_cub3d *cub);
bool			is_door(t_cub3d *cub, int x, int y);
int				is_wall(t_cub3d *cub, int x, int y);
void			minimap(t_cub3d *cub);
unsigned int	set_color(bool flag, int value);
int				init_window(t_cub3d *cub);
void			my_mlx_pixel_put(int x, int y, const t_image *img);
void			draw_line(t_vect *a, t_vect *b, const t_image *img);
void			north(t_cub3d *cub, t_vect *new_pos);
void			easth(t_cub3d *cub, t_vect *new_pos);
void			south(t_cub3d *cub, t_vect *new_pos);
void			west(t_cub3d *cub, t_vect *new_pos);
int				update_frame(void *param);
t_color			hex_to_rgb(int color);
int				rgb_to_hex(t_color rgb);
void			rotate_vector(t_vect *vector, double angle);
void			minimap_pixel_put(int x, int y, const t_image *img);
int				exit_program(t_cub3d *cub);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
int				mouse_press(int button, int x, int y, void *param);
void			move_player(int key, t_cub3d *cub);
int				handle_key(int key, t_cub3d *cub);
void			set_data(t_cub3d *cub);
void			new_sprite(t_cub3d *cub, int x, int y);
void			new_door(t_cub3d *cub, int x, int y);

#endif
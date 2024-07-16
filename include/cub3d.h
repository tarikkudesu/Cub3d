/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:13:44 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/16 11:47:51 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
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

/*-------------------- parser -------------------*/
int				parse_map(t_cub3d *cub);
int				get_map_cord(t_cub3d *cub);
int				file_parse(t_cub3d *cub, char *file);
int				check_arround(t_line *line, int i);
t_line			*new_line(char *line, int off, int last);
void			line_add_back(t_line **line, t_line *node);
void			get_min_max(t_line *line, int *min, int *max);
int				parse_line(t_cub3d *cub, char *line, int *off, int *last);
int				fill_one(t_cub3d *cub, t_map **map, t_line *line, int min);

int				is_num(char c);
int				empty(char *line);
int				all_num(char *str);
int				all_ones(t_line *line);
int				valid_char(t_cub3d *cub, char line);
int				valid_component(t_cub3d *cub, char *line);
int				wall_exist(t_line *c_line, t_line *p_line);

int				exist(char *s);
int				get_index(char *s);
char			*ft_gl(char	**buf);
char			*get_next_line(int fd);
int				ft_atoi(const char *s);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
void			change(char **s1, char **s2);
char			*strjoin(char *s1, char *s2);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_strrchr(const char *s, int c);
int				read_swap(char **buf, int fd, int *check);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_cpy(char *dst, char *src, unsigned int len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

/*---------------------- utils ---------------------*/
t_color			hex_to_rgb(int color);
bool			is_door(int x, int y);
bool			is_wall(int x, int y);
void			*talloc(size_t __size);
t_cub3d			*get_cub(t_cub3d *cub);
int				rgb_to_hex(t_color rgb);
void			clearheap(t_heap **node);
bool			is_visible(int x, int y);
t_heap			*heap_new(void *content);
int				exit_program(t_cub3d *cub);
void			putendl_fd(char *s, int fd);
void			terror(char *__err__message);
void			my_mlx_pixel_put(int x, int y);
unsigned int	set_color(bool flag, int value);
void			destroy_images(t_imgcontainer *node);
void			new_door(t_cub3d *cub, int x, int y);
void			new_sprite(t_cub3d *cub, int x, int y);
void			heap_addback(t_heap **lst, t_heap *new);
void			rotate_vector(t_vect *vector, double angle);

/*---------------------- RayCasting ---------------------*/
void			minimap(t_cub3d *cub);
void			set_data(t_cub3d *cub);
void			put_rays(t_cub3d *cub);
void			open_doors(t_cub3d *cub);
int				update_frame(void *param);
void			init_window(t_cub3d *cub);
void			set_distance(t_cub3d *cub);
void			update_doors(t_cub3d *cub);
void			set_direction(t_cub3d *cub);
void			init_textures(t_cub3d *cub);
void			dda(t_cub3d *cub, t_ray *ray);
void			initialize_data(t_cub3d *cub);
bool			set_sprite_data(t_cub3d *cub);
void			draw_line(t_vect *a, t_vect *b);
int				handle_key(int key, t_cub3d *cub);
void			move_player(t_cub3d *cub);
void			west(t_cub3d *cub, t_vect *new_pos);
void			north(t_cub3d *cub, t_vect *new_pos);
void			east(t_cub3d *cub, t_vect *new_pos);
void			south(t_cub3d *cub, t_vect *new_pos);
int				mouse_move(int x, int y, void *param);
void			put_sprites(t_cub3d *cub, int *z_coor);
int				mouse_press(int button, int x, int y, void *param);
void			minimap_pixel_put(int x, int y, const t_image *img);
int				mouse_release(int button, int x, int y, void *param);
void			render_column(t_vect *start, t_vect *end, t_ray *ray);
void			*create_image(char *filename, int *width, int *height);

#endif

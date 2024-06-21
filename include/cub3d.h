/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:04:05 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/11 22:46:56 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
// # include "../MLX/mlx.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "struct.h"
# include "macro.h"

# ifdef Z
#  define _MAL_CALL_INFO() \
    printf("\t\tFile: \033[35m%s\033[0m, Line: \033[35m%d\033[0m, Function: \033[35m%s\033[0m\n", __FILE__, __LINE__, __func__)
# endif

# ifndef Z
#  define Z 0
#  define _MAL_CALL_INFO() puts("malloc called")
# endif

char	*ft_strdup(const char *s1);
void	rotate_vector(t_vect *vector, double angle);
int		rgb_to_hex(t_color rgb);
t_color	hex_to_rgb(int color);
void	my_mlx_pixel_put(int x, int y, const t_image *img);
void	draw_line(t_vect *a, t_vect *b, const t_image *img);
int		handle_key(int key, t_cub3d *cub);
int		exit_program(t_cub3d *cub);
void	putendl_fd(char *s, int fd);
int		init_window(t_cub3d *cub);
void	*talloc(t_heap **heap, size_t __size);
void	clearheap(t_heap **node);
void	leaks(void);

/* FUNCTIONS */
void    update_doors(t_cub3d *cub);
void    put_sprites(t_cub3d *cub, int *z_coor);
t_sprite    *new_sprite(t_cub3d *cub, int x, int y);
void    sprite_addback(t_cub3d *cub, t_sprite *new);
void    north(t_cub3d *cub, t_vect *new_pos);
void    easth(t_cub3d *cub, t_vect *new_pos);
void    south(t_cub3d *cub, t_vect *new_pos);
void    west(t_cub3d *cub, t_vect *new_pos);
int     init_doors(t_cub3d *cub);
void    open_doors(t_cub3d *cub);
void	move_player(int key, t_cub3d *cub);
int		mouse_press(int button, int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
bool	is_in_cercle(int x, int y);
void	minimap_pixel_put(int x, int y, const t_image *img);
void	render_column(t_vect *start, t_vect *end, t_ray *ray, t_cub3d *cub);
int     is_wall(t_cub3d *cub, int x, int y);
bool    is_door(t_cub3d *cub, int x, int y);
int		is_wall__dda(t_cub3d *cub, t_ray *ray, int x, int y);
void	dda(t_cub3d *cub, t_ray *ray);
void	put_rays(t_cub3d *cub);
void	minimap(t_cub3d *cub);
unsigned int        set_color(bool flag, int value);
int		            update_frame(void *param);

#endif

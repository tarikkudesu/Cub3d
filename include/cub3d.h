/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:04:05 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/08 10:36:51 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../MLX/mlx.h"
// # include "../minilibx-linux/mlx.h"
// # include "../minilibx-linux/mlx_int.h"
# include "struct.h"
# include "macro.h"

# ifdef Z
#  define _MAL_CALL_INFO() \
    printf("\t\tFile: \033[35m%s\033[0m, Line: \033[35m%d\033[0m, Function: \033[35m%s\033[0m\n", __FILE__, __LINE__, __func__)
# endif

# ifndef Z
#  define Z 0
#  define _MAL_CALL_INFO() 1
# endif

/* FUNCTIONS */
int		is_wall(t_cub3d *cub, int x, int y);
int		from_rgb(t_color rgb);
t_color	to_rgb(int color);
void	dda(t_cub3d *cub, t_ray *ray);
void	put_block(int x, int y, t_cub3d *cub, int flag);
void	put_rays(t_cub3d *cub);
int		set_color(bool flag, int value);
void	put_frame_to_image(t_cub3d *cub);
int		update_frame(void *param);
void	my_mlx_pixel_put(int x, int y, const t_image *img);
void	draw_line(t_vect *a, t_vect *b, const t_image *img);
int		handle_key(int key, t_cub3d *cub);
int		exit_program(t_cub3d *cub);
void	putendl_fd(char *s, int fd);
int		init_window(t_cub3d *cub);
void	*talloc(t_heap **heap, size_t __size);
void	clearheap(t_heap **node);
void	leaks();

#endif

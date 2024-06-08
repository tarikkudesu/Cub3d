/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:04:08 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/08 12:30:22 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cub3d	t_cub3d;
typedef struct s_color	t_color;
typedef struct s_heap	t_heap;
typedef struct s_mlx	t_mlx;
typedef struct s_ray	t_ray;
typedef struct s_info	t_info;
typedef	struct s_vect	t_vect;
typedef struct s_image	t_image;
typedef struct s_player	t_player;

struct s_mlx
{
	void	*__mlx;
	void	*__win;
	void	*__intro;
};

struct	s_color
{
	int	red;
	int	green;
	int	blue;
};

struct	s_vect
{
	double	x;
	double	y;
};

struct s_ray
{
	t_vect	dir;
	double	camera;
	double	delta_x;
	double	delta_y;
	double	initial_dx;
	double	initial_dy;
	double	perp_distance;
	int		x_step;
	int		y_step;
	int		map_x;
	int		map_y;
};

struct s_image
{
	void	*__img;
	char	*__addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
};

struct s_player
{
	t_vect	pos;
	t_vect	dir;
	t_vect	plan;
};

struct s_heap
{
	void	*ptr;
	t_heap	*next;
};

struct s_info
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_color	ceiling_color;
	t_color	floor_color;
};

/*--------------------------- Main Struct -------------------------------*/
struct s_cub3d
{
	int			**map;
	t_heap		*heap;
	t_info		info;
	t_mlx		mlx;
	t_image		img;
	t_image		mini_map;
	t_player	player;
	int			panel;

	int			map_width;
	int			map_height;
	int			wall_width;
};
/*-----------------------------------------------------------------------*/

#endif

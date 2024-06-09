/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:04:08 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/09 20:36:36 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cub3d	t_cub3d;
typedef struct s_color	t_color;
typedef struct s_heap	t_heap;
typedef struct s_mlx	t_mlx;
typedef struct s_ray	t_ray;
typedef enum e_dir		t_dir;
typedef struct s_tex	t_tex;
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

enum e_dir
{
	NORTH = 'N',
	EASTH = 'E',
	SOUTH = 'S',
	WEST = 'W',
};

struct s_player
{
	t_vect	pos;
	t_vect	dir;
	t_vect	plan;
	t_dir	pole;
};

struct s_heap
{
	void	*ptr;
	t_heap	*next;
};

struct s_tex
{
	char	*file;
	t_image	img;
};

/*--------------------------- Main Struct -------------------------------*/
struct s_cub3d
{
	int			**map;
	t_color		floor_color;
	t_color		ceiling_color;
	t_heap		*heap;
	t_tex		tex[4];
	t_mlx		mlx;
	t_image		img;
	t_player	player;
	int			panel;

	int			map_width;
	int			map_height;
	int			wall_width;
};
/*-----------------------------------------------------------------------*/

#endif

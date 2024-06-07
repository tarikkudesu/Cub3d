/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:04:08 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/06 12:04:43 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cub3d	t_cub3d;
typedef struct s_heap	t_heap;
typedef struct s_mlx	t_mlx;
typedef struct s_ray	t_ray;
typedef	struct s_vect	t_vect;
typedef struct s_image	t_image;
typedef struct s_player	t_player;

struct s_mlx
{
	void	*__mlx;
	void	*__win;
	void	*__intro;
};

struct	s_vect
{
	float	x;
	float	y;
};

struct s_ray
{
	t_vect	dir;
	double	camera;
	double	delta_x;
	double	delta_y;
	double	initial_dx;
	double	initial_dy;
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

/*--------------------------- Main Struct -------------------------------*/
struct s_cub3d
{
	int			**map;
	t_heap		*heap;
	t_image		img;
	t_image		img_3d;
	t_mlx		mlx;
	t_ray		ray;
	t_player	player;
	int			panel;

	int			p_x;
	int			p_y;
	int			map_width;
	int			map_height;
	int			wall_width;
};
/*-----------------------------------------------------------------------*/

struct s_heap
{
	void	*ptr;
	t_heap	*next;
};


#endif

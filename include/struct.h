/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:16:36 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 16:58:08 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_line			t_line;
typedef struct s_cub3d			t_cub3d;
typedef struct s_color			t_color;
typedef struct s_heap			t_heap;
typedef struct s_mlx			t_mlx;
typedef struct s_ray			t_ray;
typedef struct s_map			t_map;
typedef enum e_dir				t_dir;
typedef struct s_tex			t_tex;
typedef struct s_vect			t_vect;
typedef struct s_door			t_door;
typedef struct s_image			t_image;
typedef struct s_sprite			t_sprite;
typedef struct s_player			t_player;
typedef struct s_imgcontainer	t_imgcontainer;

struct s_imgcontainer
{
	void			*image;
	t_imgcontainer	*next;
};

struct s_line
{
	int			y;
    int			off;
    int			last;
    char		*line;
    t_line		*next;
    t_line		*prev;
};

struct s_map
{
	int		v;
	bool	wall;
	bool	door;
	bool	visited;
};

struct s_mlx
{
	void	*__mlx;
	void	*__win;
	void	*__intro;
	void	*__menu;
};

struct s_door
{
	int		x;
	int		y;
	int		timer;
	int		isopen;
	int		ismoving;
	double	progress;
	t_door	*next;
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
	double	tex_pos_x;
	int		height;
	int		column;
	int		x_step;
	int		y_step;
	int		map_x;
	int		map_y;
	int		side;
};

struct s_image
{
	void	*__img;
	int		*__addr;
	int		pixel_bits;
	int		line_bytes;
	int		width;
	int		height;
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

struct s_sprite
{
	double		x;
	double		y;
	int			width;
	int			height;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			index;
	bool		visible;
	double		distance;
	t_sprite	*next;
};

struct s_cub3d
{
	t_map			**map;
	t_color			floor_color;
	t_color			ceiling_color;
	t_image			sprite_img[40];
	t_imgcontainer	*imgcontainer;
	t_tex			tex[5];
	t_mlx			mlx;
	t_image			img;
	int				frame;
	t_player		player;
	t_sprite		*sprites_list;
	char			*frames[40];
	int				sprites_n;
	t_sprite		*sprite;
	t_door			*doors;
	t_heap			*heap;
	t_line			*line;

	int				player_nbr;
	int				mode;
	int				button;
	int				map_width;
	int				map_height;
	int				wall_width;
};

#endif

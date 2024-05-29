/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:04:08 by tamehri           #+#    #+#             */
/*   Updated: 2024/05/12 10:04:09 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

# define ERR_MLX_XPM		"Error : mlx_xpm_file_to_image error"
# define ERR_ARG			"Error : Wrong number of arguments"
# define ERR_MLX_ADDRESS	"Error : mlx_get_data_addr error"
# define ERR_OPEN			"Error : Error opening the file"
# define ERR_READ			"Error : Error reading the file"
# define ERR_MLX_WIN		"Error : mlx_new_window error"
# define ERR_MLX_IMG		"Error : mlx_new_image error"
# define ERR_FILE			"Error : Wrong file format"
# define ERR_MLX_INIT		"Error : mlx_init error"
# define ERR_MAL			"Error : malloc error"
# define ERR_EMTY			"Error : empty file"

# define HEIGHT		800
# define WIDTH		1220
# define mapWidth	24 //temp
# define mapHeight	24 //temp

# define UP			126
# define DOWN		125
# define RIGHT		124
# define LEFT		123
# define ESC		53
# define ESC_L		65307

typedef struct s_cub3d	t_cub3d;
typedef struct s_heap	t_heap;
typedef struct s_mlx	t_mlx;
typedef struct s_image	t_image;

struct s_mlx
{
	void	*__mlx;
	void	*__win;
};

struct s_image
{
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
};

struct s_cub3d
{
	t_heap	*heap;
	t_mlx	mlx;
	t_img	img;
};

struct s_heap
{
	void	*ptr;
	t_heap	*next;
};

#endif

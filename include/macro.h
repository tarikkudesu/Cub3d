/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:24:23 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/03 18:27:49 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

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

# define mapWidth		24 //temp
# define mapHeight		24 //temp

# define WIDTH			1200
# define HEIGHT			800
# define FOV			60
# define ROT_SPEED		0.045
# define PLAYER_SPEED	4

# define SPACE			49

# define UP				126
# define DOWN			125
# define RIGHT			124
# define LEFT			123

# define W				13
# define S				1
# define D				2
# define A				0

# define ESC			53
# define ESC_L			65307

# define INTRO			1
# define GAME			0

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF

#endif

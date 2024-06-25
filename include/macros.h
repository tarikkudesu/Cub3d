/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:11:05 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 17:20:54 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define ERR_MLX_XPM		"Error : mlx_xpm_file_to_image error"
# define ERR_ARG			"Error : Wrong number of arguments"
# define ERR_MLX_ADDRESS	"Error : mlx_get_data_addr error"
# define ERR_OPEN			"Error : Error opening the file"
# define ERR_READ			"Error : Error reading the file"
# define ERR_MLX_WIN		"Error : mlx_new_window error"
# define ERR_MLX_IMG		"Error : mlx_new_image error"
# define ERR_FILE			"Error : Wrong file format"
# define ERR_MLX_INIT		"Error : mlx_init error"
# define ERR_MAL			"Error : talloc error"
# define ERR_EMTY			"Error : empty file"

# define PI_1			0.0174533
# define WIDTH			1200
# define HEIGHT			800

# define SPACE			49
# define UP				126
# define DOWN			125
# define RIGHT			124
# define LEFT			123
# define Q				12
# define W				13
# define S				1
# define D				2
# define A				0
# define ESC			53

# define MENU			2
# define MINIMAP		3
# define INTRO			1
# define GAME			0

# define BLACK		0x000000
# define BACKGROUND	0x081020
# define WHITE		0xFFFFFF
# define CYAN		0x74f9ff

#endif
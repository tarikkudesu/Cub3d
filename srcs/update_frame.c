/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:18:34 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/11 22:33:20 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int worldMap[mapWidth][mapHeight] =
// {
// {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 1, 1, 1, 1, 2, 1, 1, 1, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 2, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// {1, 0, 1, 1, 1, 1, 2, 1, 1, 1, 1},
// {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// };

int	set_color(bool flag, int value)
{
	static int	color;

	if (flag == true)
		color = value;
	return (color);
}

static void	put_background(t_cub3d *cub)
{
	int	w;
	int	h;

	w = -1;
	while (++w < WIDTH)
	{
		h = -1;
		set_color(1, rgb_to_hex(cub->ceiling_color));
		while (++h < HEIGHT / 2)
			my_mlx_pixel_put(w, h, &cub->img);
		set_color(1, rgb_to_hex(cub->floor_color));
		while (++h < HEIGHT)
			my_mlx_pixel_put(w, h, &cub->img);
	}
}

int	update_frame(void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	if (cub->mode == INTRO)
		mlx_put_image_to_window(cub->mlx.__mlx, \
			cub->mlx.__win, cub->mlx.__intro, 0, 0);
	else if (cub->mode == MENU)
		mlx_put_image_to_window(cub->mlx.__mlx, \
			cub->mlx.__win, cub->mlx.__menu, 0, 0);
	else if (cub->mode == GAME)
	{
		update_doors(cub);
		put_background(cub);
		put_sprites(cub);
		put_rays(cub);
		minimap(cub);
		mlx_put_image_to_window(cub->mlx.__mlx, \
			cub->mlx.__win, cub->img.__img, 0, 0);
	}
	return (0);
}

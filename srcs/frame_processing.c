/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:03:25 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/09 17:15:57 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[mapWidth][mapHeight] =
{
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 1, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 4, 1, 4, 1, 4, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 4, 1, 0, 1, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int	set_color(bool flag, int value)
{
	static int	color;

	if (flag == true)
		color = value;
	return (color);
}

void	put_player(t_cub3d *cub)
{
	set_color(true, YELLOW);
	for (int i = (cub->player.pos.x * 64) - 5; i < (cub->player.pos.x * 64) + 5; i++) {
		for (int j = (cub->player.pos.y * 64) - 5; j < (cub->player.pos.y * 64) + 5; j++)
			my_mlx_pixel_put(i, j, &cub->img);
	}
}

void	put_background(t_cub3d *cub)
{
	int	w;
	int	h;

	w = -1;
	while (++w < WIDTH)
	{
		h = -1;
		set_color(1, from_rgb(cub->info.ceiling_color));
		while (++h < HEIGHT / 2)
			my_mlx_pixel_put(w, h, &cub->img);
		set_color(1, from_rgb(cub->info.floor_color));
		while (++h < HEIGHT)
			my_mlx_pixel_put(w, h, &cub->img);
	}
}



void	put_frame_to_image(t_cub3d *cub)
{
	put_background(cub);
	put_rays(cub);
	put_minimap(cub);
	mlx_put_image_to_window(cub->mlx.__mlx, \
		cub->mlx.__win, cub->img.__img, 0, 0);
}

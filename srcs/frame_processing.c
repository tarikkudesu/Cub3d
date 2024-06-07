/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:03:25 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/07 17:23:30 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[mapWidth][mapHeight] =
{
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 0, 1, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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

void	put_block(int x, int y, t_cub3d *cub, int flag)
{
	if (flag)
	{
		for (int i = x; i < x + cub->wall_width; i++) {
			for (int j = y; j < y + cub->wall_width; j++)
				my_mlx_pixel_put(i, j, &cub->img);
		}
	}
	for (int i = x; i < x + cub->wall_width; i++) {
		my_mlx_pixel_put(i, y, &cub->img);
		my_mlx_pixel_put(i, y + cub->wall_width, &cub->img);
	}
	for (int j = y; j < y + cub->wall_width; j++) {
		my_mlx_pixel_put(x, j, &cub->img);
		my_mlx_pixel_put(x + cub->wall_width, j, &cub->img);
		
	}
		
}

void	put_map(t_cub3d *cub)
{
	set_color(true, CYAN);
	for (int i = 0; i < cub->map_width; i++) {
		for (int j = 0; j < cub->map_height; j++) {
			if (worldMap[j][i] != 0)
				put_block(j * cub->wall_width, i * cub->wall_width, cub, 1);
			else
				put_block(j * cub->wall_width, i * cub->wall_width, cub, 0);
		}
	}
}

void	put_frame_to_image(t_cub3d *cub)
{

	set_color(1, BACKGROUND);
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			my_mlx_pixel_put(i, j, &cub->img);
		}
	}
	for (int i = WIDTH; i < WIDTH * 2; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			my_mlx_pixel_put(i, j, &cub->img_3d);
		}
	}
	put_map(cub);
	put_ray(cub);
	put_player(cub);
	mlx_put_image_to_window(cub->mlx.__mlx, \
		cub->mlx.__win, cub->img.__img, 0, 0);
	mlx_put_image_to_window(cub->mlx.__mlx, \
		cub->mlx.__win, cub->img_3d.__img, WIDTH, 0);
}

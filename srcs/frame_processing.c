/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:03:25 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/03 21:34:29 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[mapWidth][mapHeight] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
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
	for (int i = cub->player.x_pos - 15; i < cub->player.x_pos + 15; i++) {
		for (int j = cub->player.y_pos - 15; j < cub->player.y_pos + 15; j++)
			my_mlx_pixel_put(i, j, &cub->img);
	}
}

void	put_background(t_cub3d *cub)
{
	set_color(true, BLACK);
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++)
			my_mlx_pixel_put(i, j, &cub->img);
	}
}

void	put_block(int x, int y, t_cub3d *cub)
{
	for (int i = x; i < x + 30; i++) {
		for (int j = y; j < y + 30; j++)
			my_mlx_pixel_put(i, j, &cub->img);
	}
		
}

void	put_map(t_cub3d *cub)
{
	set_color(true, WHITE);
	for (int i = 0; i < cub->map_width; i++) {
		for (int j = 0; j < cub->map_height; j++) {
			if (worldMap[i][j] != 0)
				put_block(i * 30, j * 30, cub);
		}
	}
}

void	put_ray(t_cub3d *cub)
{
	t_p	start;
	t_p	end;

	cub->ray.angle = cub->player.angle;
	set_color(true, GREEN);
	start.x = cub->player.x_pos;
	start.y = cub->player.y_pos;
	end.x = start.x + cub->ray.distance * cos(cub->player.angle);	
	end.y = start.y + cub->ray.distance * sin(cub->player.angle);
	draw_line(&start, &end, &cub->img);
}

void	put_frame_to_image(t_cub3d *cub)
{
	put_background(cub);
	put_map(cub);
	put_ray(cub);
	put_player(cub);
	
	mlx_put_image_to_window(cub->mlx.__mlx, \
		cub->mlx.__win, cub->img.__img, 0, 0);
}
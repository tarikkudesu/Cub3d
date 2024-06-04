/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:03:25 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/04 21:43:35 by tamehri          ###   ########.fr       */
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
  {1,0,0,0,0,0,2,0,1,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
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
	for (int i = cub->player.x_pos - 5; i < cub->player.x_pos + 5; i++) {
		for (int j = cub->player.y_pos - 5; j < cub->player.y_pos + 5; j++)
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

void	put_ray(t_cub3d *cub)
{
	t_p	start;
	t_p	end;

	set_color(true, GREEN);
	cub->ray.angle = cub->player.angle;
	cub->ray.angle = cub->player.angle - M_PI / 9;
	while (cub->ray.angle < cub->player.angle + M_PI / 9)
	{
		start.x = cub->player.x_pos;
		start.y = cub->player.y_pos;
		end = end_point(cub, start);
		draw_line(&start, &end, &cub->img);
		cub->ray.angle += 0.01;
	}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:03:25 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/08 14:00:53 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[mapWidth][mapHeight] =
{
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 1, 1, 4, 1, 4, 1, 4, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 1, 1, 4, 1, 0, 1, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 5, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
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

bool	is_in_cercle(int x, int y)
{
	int	dx;
	int	dy;
	int	distance;
	
	dx = x - 100;
	dy = y - 100;
	distance = dx * dx + dy * dy;
	if (distance <= 10000)
		return (true);
	return (false);
}

void	my_mlx_pixel(int x, int y, const t_image *img)
{
	int		*addr;
	int		pixel;

	addr = (int *)img->__addr;
	pixel = y * img->line_bytes / 4 + x;
	if (x < MINI_MAP_W && x >= 0 && y < MINI_MAP_H && y >= 0)
	{
		if (is_in_cercle(x, y))
			addr[pixel] = set_color(false, 0);
		else
			addr[pixel] = WHITE;
	}
}

void	put_block(int x, int y, t_cub3d *cub, int flag)
{
	if (flag)
	{
		for (int i = x; i < x + cub->wall_width; i++) {
			for (int j = y; j < y + cub->wall_width; j++)
				my_mlx_pixel(i, j, &cub->mini_map);
		}
	}
	for (int i = x; i < x + cub->wall_width; i++) {
		my_mlx_pixel(i, y, &cub->mini_map);
		my_mlx_pixel(i, y + cub->wall_width, &cub->mini_map);
	}
	for (int j = y; j < y + cub->wall_width; j++) {
		my_mlx_pixel(x, j, &cub->mini_map);
		my_mlx_pixel(x + cub->wall_width, j, &cub->mini_map);
	}
		
}

void	put_minimap(t_cub3d *cub)
{
	set_color(true, BLACK);
	for (int i = 0; i < MINI_MAP_W; i++) {
		for (int j = 0; j < MINI_MAP_H; j++)
			my_mlx_pixel(i, j, &cub->mini_map);
	}
	set_color(true, YELLOW);
	for (int i = 0; i < cub->map_width; i++) {
		for (int j = 0; j < cub->map_height; j++) {
			if (worldMap[i][j] != 0)
				put_block((i - cub->player.pos.x) * cub->wall_width + MINI_MAP_W / 2, (j - cub->player.pos.y) * cub->wall_width + MINI_MAP_H / 2, cub, 1);
			else
				put_block((i - cub->player.pos.x) * cub->wall_width + MINI_MAP_W / 2, (j - cub->player.pos.y) * cub->wall_width + MINI_MAP_H / 2, cub, 0);
		}
	}
	set_color(true, WHITE);
	for (int i = MINI_MAP_W / 2 - 4; i < MINI_MAP_W / 2 + 4; i++) {
		for (int j = MINI_MAP_H / 2 - 4; j < MINI_MAP_H / 2 + 4; j++)
			my_mlx_pixel(i, j, &cub->mini_map);
	}
	t_vect	start;
	t_vect	end;
	t_vect	dir;
	start.x = 100;
	start.y = 100;
	dir.x = cub->player.dir.x;
	dir.y = cub->player.dir.y;
	rotate_vector(&dir, - PI_1 * 2w0);
	for (int i = 0; i < 40; i++) {
		rotate_vector(&dir, PI_1);
		end.x = start.x + 100 * dir.x;
		end.y = start.y + 100 * dir.y;
		draw_line(&start, &end, &cub->mini_map);
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
	mlx_put_image_to_window(cub->mlx.__mlx, \
		cub->mlx.__win, cub->mini_map.__img, 0, 0);
}

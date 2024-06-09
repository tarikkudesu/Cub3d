/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:36:29 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/09 17:39:25 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

extern int worldMap[mapWidth][mapHeight];

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
	}
}

void	put_block(int x, int y, t_cub3d *cub, int flag)
{
	int	w;
	int	h;

	w = x - 1;
	while (flag && ++w < x + cub->wall_width)
	{
		h = y - 1;
		while (flag && ++h < y + cub->wall_width)
			my_mlx_pixel(w, h, &cub->img);
	}
	w = x - 1;
	while (++w < x + cub->wall_width)
	{
		my_mlx_pixel(w, y, &cub->img);
		my_mlx_pixel(w, y + cub->wall_width, &cub->img);
	}
	h = y - 1;
	while (++h < y + cub->wall_width)
	{
		my_mlx_pixel(x, h, &cub->img);
		my_mlx_pixel(x + cub->wall_width, h, &cub->img);
	}
}

void	put_minimap(t_cub3d *cub)
{
	set_color(true, BACKGROUND);
	for (int i = 0; i < MINI_MAP_W; i++) {
		for (int j = 0; j < MINI_MAP_H; j++)
			my_mlx_pixel(i, j, &cub->img);
	}
	set_color(true, WHITE);
	for (int i = 0; i < cub->map_width; i++) {
		for (int j = 0; j < cub->map_height; j++) {
			if (worldMap[i][j] != 0)
				put_block((i - cub->player.pos.x) * cub->wall_width + MINI_MAP_W / 2, (j - cub->player.pos.y) * cub->wall_width + MINI_MAP_H / 2, cub, 1);
			else
				put_block((i - cub->player.pos.x) * cub->wall_width + MINI_MAP_W / 2, (j - cub->player.pos.y) * cub->wall_width + MINI_MAP_H / 2, cub, 0);
		}
	}
	set_color(true, CYAN);
	for (int i = MINI_MAP_W / 2 - 2; i < MINI_MAP_W / 2 + 2; i++) {
		for (int j = MINI_MAP_H / 2 - 2; j < MINI_MAP_H / 2 + 2; j++)
			my_mlx_pixel(i, j, &cub->img);
	}
	t_vect	start;
	t_vect	end;
	t_vect	dir;
	start.x = 100;
	start.y = 100;
	dir.x = cub->player.dir.x;
	dir.y = cub->player.dir.y;
	rotate_vector(&dir, - PI_1 * 30);
	for (int i = 0; i < 30; i++) {
		rotate_vector(&dir, PI_1 * 2);
		end.x = start.x + 100 * dir.x;
		end.y = start.y + 100 * dir.y;
		draw_line(&start, &end, &cub->img);
	}
}

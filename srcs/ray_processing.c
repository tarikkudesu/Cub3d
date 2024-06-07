/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:27:54 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/06 19:22:41 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

extern int worldMap[mapWidth][mapHeight];

float hypotenuse(t_vect *a, t_vect *b)
{
	double	opposite;
	double	adjacent;

	adjacent = fabsf(a->x - a->y);
	opposite = fabsf(b->x - b->y);
	return (sqrt(adjacent * adjacent + opposite * opposite));
}

int	is_wall(t_cub3d *cub, int x, int y)
{
	if (x >= 0 && x < cub->map_width && y >= 0 && y < cub->map_width)
	{
		if (worldMap[x][y] != 0)
			return (1);	
	}
	return (0);
}

void	put_ray(t_cub3d *cub)
{
	int		mapx;
	int		mapy;
	double	stepX;
	double	stepY;

	set_color(1, GREEN);

	int wall = 0;
	int side = 0;
	double camera;
	int distance;
	for (int i = 0; i < WIDTH; i++) {
		camera = (2 * i / (double)WIDTH - 1);
		cub->ray.dir.x = cub->player.dir.x + cub->player.plan.x * camera;
		cub->ray.dir.y = cub->player.dir.y + cub->player.plan.y * camera;
		mapx = (int)cub->player.pos.x;
		mapy = (int)cub->player.pos.y;
		if (cub->ray.dir.x == 0)
			cub->ray.delta_x = 1e30;
		else
			cub->ray.delta_x = fabs((1 / cub->ray.dir.x));
		if (cub->ray.dir.y == 0)
			cub->ray.delta_y = 1e30;
		else
			cub->ray.delta_y = fabs((1 / cub->ray.dir.y));

		if (cub->ray.dir.x < 0)
		{
			stepX = -1;
			cub->ray.initial_dx = (cub->player.pos.x - mapx) * cub->ray.delta_x;
		}
		else
		{
			stepX = 1;
			cub->ray.initial_dx = (mapx + 1 - cub->player.pos.x) * cub->ray.delta_x;
		}

		if (cub->ray.dir.y < 0)
		{
			stepY = -1;
			cub->ray.initial_dy = (cub->player.pos.y - mapy) * cub->ray.delta_y;
		}
		else
		{
			stepY = 1;
			cub->ray.initial_dy = (mapy + 1.0 - cub->player.pos.y) * cub->ray.delta_y;
		}
		wall = 0;
		while (wall == 0)
		{
			if (cub->ray.initial_dx < cub->ray.initial_dy)
			{
				cub->ray.initial_dx += cub->ray.delta_x;
				mapx += stepX;
				side = 0;
			}
			else
			{
				cub->ray.initial_dy += cub->ray.delta_y;
				mapy += stepY;
				side = 1;
			}
			if (mapx < 0 || mapx > mapWidth || mapy < 0 || mapy > mapHeight || worldMap[mapx][mapy] != 0)
				wall = 1;
		}
		if (side == 0)
			distance = cub->ray.initial_dx - cub->ray.delta_x;
		else
			distance = cub->ray.initial_dy - cub->ray.delta_y;
		
		double height = (double)HEIGHT / distance;
		t_vect	start;
		t_vect	end;
		start.x = i;
		end.x = i;
		start.y = HEIGHT / 2 - height / 2;
		if (start.y < 0)
			start.y = 0;
		end.y = HEIGHT / 2 + height / 2;
		if (end.y > HEIGHT)
			end.y = HEIGHT;
		set_color(1, WHITE);
		draw_line(&start, &end, &cub->img_3d);
		// put_block(mapx * cub->wall_width, mapy * cub->wall_width, cub, 1);
		// distance = 
	}
}

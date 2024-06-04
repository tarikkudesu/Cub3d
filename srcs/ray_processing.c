/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:27:54 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/04 21:46:04 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

extern int worldMap[mapWidth][mapHeight];

float hypotenuse(t_cub3d *cub, t_p end)
{
	double	opposite;
	double	adjacent;

	adjacent = abs(cub->player.x_pos - end.x);
	opposite = abs(cub->player.y_pos - end.y);
	return (sqrt(pow(adjacent, 2) + pow(opposite, 2)));
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

t_p	horizontal_intersection(t_cub3d *cub, t_p start)
{
	t_p		first_inter;

	if (cub->ray.angle <= M_PI)
		first_inter.y = (int)(start.y / cub->wall_width) \
			* cub->wall_width - 1;
	else
		first_inter.y = (int)(start.y / cub->wall_width) \
			* cub->wall_width + cub->wall_width;
	first_inter.x = start.x + \
		(start.y - first_inter.y) / tan(M_PI - cub->ray.angle);
	if (is_wall(cub, first_inter.x / cub->wall_width, first_inter.y / cub->wall_width))
		return (first_inter);
	return (first_inter);
}


t_p	vertical_intersection(t_cub3d *cub, t_p start)
{
	t_p	first_inter;

	if (cub->ray.angle >= M_PI / 2 && cub->ray.angle <= (3 * M_PI) / 2)
		first_inter.x = (int)(start.x / cub->wall_width) \
			* cub->wall_width + cub->wall_width;
	else if (cub->ray.angle < M_PI / 2 || cub->ray.angle > (3 * M_PI) / 2)
		first_inter.x = (int)(start.x / cub->wall_width) \
			* cub->wall_width - 1;
	first_inter.y = start.y + \
		(start.x - first_inter.x) * tan(M_PI - cub->ray.angle);
	return (first_inter);
}

t_p	end_point(t_cub3d *cub, t_p start)
{
	t_p	horizontal_end;
	t_p	vertical_end;
	t_p	end;

	horizontal_end = horizontal_intersection(cub, start);
	vertical_end = vertical_intersection(cub, start);
	if (hypotenuse(cub, horizontal_end) < hypotenuse(cub, vertical_end))
		end = horizontal_end;
	else
		end = vertical_end;
	if (is_wall(cub, end.x / cub->wall_width, end.y / cub->wall_width))
		return (end);
	return (end_point(cub, end));
}
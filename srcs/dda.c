/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:21:02 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/08 10:39:02 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

extern int worldMap[mapWidth][mapHeight];

int	is_wall(t_cub3d *cub, int x, int y)
{
	if (x >= 0 && x < cub->map_width && y >= 0 && y < cub->map_width)
	{
		if (worldMap[x][y] != 0)
			return (1);
	}
	return (0);
}

void	dda(t_cub3d *cub, t_ray *ray)
{
	int	side;

	side = 0;
	while (0 == is_wall(cub, ray->map_x, ray->map_y))
	{
		if (ray->initial_dx < ray->initial_dy)
		{
			ray->initial_dx += ray->delta_x;
			ray->map_x += ray->x_step;
			side = 0;
		}
		else
		{
			ray->initial_dy += ray->delta_y;
			ray->map_y += ray->y_step;
			side = 1;
		}
	}
	if (side == 0) {
		ray->perp_distance = ray->initial_dx - ray->delta_x; set_color(1, CYAN);
	}
	else {
		ray->perp_distance = ray->initial_dy - ray->delta_y; set_color(1, CYAN_D);
	}
}

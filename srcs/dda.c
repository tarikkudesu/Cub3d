/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:21:02 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/10 19:45:37 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

extern int worldMap[mapWidth][mapHeight];

int	is_wall(t_cub3d *cub, int x, int y)
{
	if (x >= 0 && x < cub->map_width && y >= 0 && y < cub->map_width)
	{
		if (worldMap[x][y] == 0)
			return (0);
	}
	return (1);
}

void	dda(t_cub3d *cub, t_ray *ray)
{
	while (0 == is_wall(cub, ray->map_x, ray->map_y))
	{
		if (ray->initial_dx < ray->initial_dy)
		{
			ray->initial_dx += ray->delta_x;
			ray->map_x += ray->x_step;
			ray->side = 0;
		}
		else
		{
			ray->initial_dy += ray->delta_y;
			ray->map_y += ray->y_step;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
	{
		ray->perp_distance = ray->initial_dx - ray->delta_x;
		ray->tex_pos_x = cub->player.pos.y + ray->perp_distance * ray->dir.y;
	}
	else
	{
		ray->perp_distance = ray->initial_dy - ray->delta_y;
		ray->tex_pos_x = cub->player.pos.x + ray->perp_distance * ray->dir.x;
	}
	ray->tex_pos_x -= (int)ray->tex_pos_x;
}

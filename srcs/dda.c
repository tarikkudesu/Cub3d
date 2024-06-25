/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:14:14 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 19:47:26 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_ray_data(t_cub3d *cub, t_ray *ray)
{
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

static int	door_hit(t_cub3d *cub, t_ray *ray, int x, int y)
{
	t_door	*tmp;

	tmp = cub->doors;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
		{
			if (!tmp->isopen)
			{
				set_ray_data(cub, ray);
				if (ray->tex_pos_x <= tmp->progress)
					return (0);
				else
				{
					ray->tex_pos_x -= tmp->progress;
					return (2);
				}
			}
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	hit(t_cub3d *cub, t_ray *ray, int x, int y)
{
	if (x >= 0 && x < cub->map_height && y >= 0 && y < cub->map_width)
		cub->map[x][y].visited = true;
	if (is_door(cub, x, y))
		return (door_hit(cub, ray, x, y));
	return (is_wall(cub, x, y));
}

void	dda(t_cub3d *cub, t_ray *ray)
{
	int	rt;

	rt = 0;
	while (rt == 0)
	{
		rt = hit(cub, ray, ray->map_x, ray->map_y);
		if (rt != 0)
			break ;
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
	if (rt != 2)
		set_ray_data(cub, ray);
}

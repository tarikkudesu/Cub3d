/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:12:05 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/27 09:04:56 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_ray(t_cub3d *cub, t_ray *ray)
{
	ray->map_x = (int)cub->player.pos.x;
	ray->map_y = (int)cub->player.pos.y;
	if (ray->dir.x < 0)
		ray->x_step = -1;
	if (ray->dir.x < 0)
		ray->initial_dx = (cub->player.pos.x - ray->map_x) * ray->delta_x;
	else
	{
		ray->x_step = 1;
		ray->initial_dx = (ray->map_x + 1 - cub->player.pos.x) * ray->delta_x;
	}
	if (ray->dir.y < 0)
		ray->y_step = -1;
	if (ray->dir.y < 0)
		ray->initial_dy = (cub->player.pos.y - ray->map_y) * ray->delta_y;
	else
	{
		ray->y_step = 1;
		ray->initial_dy = (ray->map_y + 1 - cub->player.pos.y) * ray->delta_y;
	}
}

static void	put_ray(t_ray *ray, int x)
{
	t_vect	start;
	t_vect	end;

	ray->height = (int)(HEIGHT / ray->perp_distance);
	start.x = x;
	end.x = x;
	start.y = HEIGHT / 2 - ray->height / 2;
	end.y = HEIGHT / 2 + ray->height / 2;
	render_column(&start, &end, ray);
}

void	put_rays(t_cub3d *cub)
{
	int		z_coor[WIDTH];
	t_ray	ray;
	int		i;

	i = -1;
	while (++i < WIDTH)
	{
		ray.column = i;
		ray.camera = 2 * i / (double)WIDTH - 1;
		ray.dir.x = cub->player.dir.x + cub->player.plan.x * ray.camera;
		ray.dir.y = cub->player.dir.y + cub->player.plan.y * ray.camera;
		if (ray.dir.x == 0)
			ray.delta_x = 1e3;
		else
			ray.delta_x = fabs(1 / ray.dir.x);
		if (ray.dir.y == 0)
			ray.delta_y = 1e3;
		else
			ray.delta_y = fabs(1 / ray.dir.y);
		set_ray(cub, &ray);
		dda(cub, &ray);
		put_ray(&ray, i);
		z_coor[i] = ray.height;
	}
	put_sprites(cub, z_coor);
}

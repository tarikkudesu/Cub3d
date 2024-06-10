/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:05:18 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/10 20:48:51 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_tex_idx(t_ray *ray)
{
	int	idx;

	if (ray->side)
	{
		if (ray->dir.y > 0)
			idx = 0;
		else
			idx = 1;
	}
	else
	{
		if (ray->dir.x > 0)
			idx = 2;
		else
			idx = 3;
	}
	return (idx);
}

void	render_wall(t_vect *start, t_vect *end, t_ray *ray, t_cub3d *cub)
{
	double	perc;
	int		limits[2];
	int		tex[2];

	int idx = 0;
	if (start->y < 0)
		limits[0] = 0;
	else
		limits[0] = (int)start->y;
	if (end->y >= HEIGHT)
		limits[1] = HEIGHT;
	else
		limits[1] = (int)end->y;
	idx = get_tex_idx(ray);
	tex[0] = ray->tex_pos_x * cub->tex[idx].img.width;
	while (limits[0] < limits[1])
	{
		perc = ((limits[0] - start->y) / (end->y - start->y));
		tex[1] = perc * cub->tex[idx].img.height;
		set_color(1, cub->tex[idx].img.__addr[cub->tex[idx].img.height * tex[1] + tex[0]]);
		my_mlx_pixel_put(ray->column, limits[0], &cub->img);
		limits[0]++;
	}
}

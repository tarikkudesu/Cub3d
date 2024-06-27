/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:15:01 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/27 09:43:59 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_tex	*get_texture(t_ray *ray)
{
	t_cub3d	*cub;

	cub = get_cub(NULL);
	if (ray->side && ray->dir.y > 0)
		return (&cub->tex[0]);
	else if (ray->side)
		return (&cub->tex[1]);
	else if (!ray->side && ray->dir.x > 0)
		return (&cub->tex[2]);
	return (&cub->tex[3]);
}

static void	render_door(t_vect *start, t_vect *end, t_ray *ray, t_cub3d *cub)
{
	int		t_x;
	int		t_y;
	int		y;

	y = (int)start->y;
	if (start->y < 0)
		y = 0;
	t_x = ray->tex_pos_x * cub->tex[4].img.width;
	while (y < HEIGHT && y < (int)end->y)
	{
		t_y = ((y - start->y) / (end->y - start->y)) * cub->tex[4].img.height;
		set_color(1, cub->tex[4].img.__addr[cub->tex[4].img.height \
			* t_y + t_x]);
		my_mlx_pixel_put(ray->column, y);
		y++;
	}
}

static void	render_wall(t_vect *start, t_vect *end, t_ray *ray)
{
	t_tex	*tex;
	int		t_x;
	int		t_y;
	int		y;

	y = (int)start->y;
	if (start->y < 0)
		y = 0;
	tex = get_texture(ray);
	t_x = ray->tex_pos_x * tex->img.width;
	while (y < HEIGHT && y < (int)end->y)
	{
		t_y = ((y - start->y) / (end->y - start->y)) * tex->img.height;
		set_color(1, tex->img.__addr[tex->img.height \
			* t_y + t_x]);
		my_mlx_pixel_put(ray->column, y);
		y++;
	}
}

void	render_column(t_vect *start, t_vect *end, t_ray *ray)
{
	t_cub3d	*cub;

	cub = get_cub(NULL);
	if (is_door(ray->map_x, ray->map_y))
		render_door(start, end, ray, cub);
	else
		render_wall(start, end, ray);
}

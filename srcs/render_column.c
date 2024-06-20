/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:05:18 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/11 22:26:41 by tamehri          ###   ########.fr       */
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
		my_mlx_pixel_put(ray->column, y, &cub->img);
		y++;
	}
}

static void	render_wall(t_vect *start, t_vect *end, t_ray *ray, t_cub3d *cub)
{
	int		t_x;
	int		t_y;
	int		t;
	int		y;

	y = (int)start->y;
	if (start->y < 0)
		y = 0;
	t = get_tex_idx(ray);
	t_x = ray->tex_pos_x * cub->tex[t].img.width;
	while (y < HEIGHT && y < (int)end->y)
	{
		t_y = ((y - start->y) / (end->y - start->y)) * cub->tex[t].img.height;
		set_color(1, cub->tex[t].img.__addr[cub->tex[t].img.height \
			* t_y + t_x]);
		my_mlx_pixel_put(ray->column, y, &cub->img);
		y++;
	}
}

static void	put_sprite(t_cub3d *cub, t_ray *ray, int x)
{
	int	tex_x;
	int	tex_y;
	int i;

	if (x < cub->sprites->start_x || x > cub->sprites->end_x)
		return;
	if (ray->height >= cub->sprites->height)
		return ;
	tex_x = (double)(x - cub->sprites->start_x) / \
		(cub->sprites->end_x - cub->sprites->start_x) * cub->sprite_img.width;
	i = cub->sprites->start_y - 1;
	while (++i < cub->sprites->end_y)
	{
		if (i < 0 || i >= HEIGHT)
			continue ;
		tex_y = (double)(i - cub->sprites->start_y) / \
			(cub->sprites->end_y - cub->sprites->start_y) * cub->sprite_img.height;
		set_color(1, cub->sprite_img.__addr[cub->sprite_img.height * tex_y + tex_x]);
		if (set_color(0, 0) != 0x000000)
			my_mlx_pixel_put(x, i, &cub->img);
	}
}

void	render_column(t_vect *start, t_vect *end, t_ray *ray, t_cub3d *cub)
{
	if (is_door(cub, ray->map_x, ray->map_y))
		render_door(start, end, ray, cub);
	else
		render_wall(start, end, ray, cub);
	put_sprite(cub, ray, ray->column);
}

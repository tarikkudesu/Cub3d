/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:16:03 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 09:51:43 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_visible(t_cub3d *cub, int x, int y)
{
	return (cub->map[x][y].visited);
}

static void	transform_sprite(t_cub3d *cub, double *trans_x, double *trans_y)
{
	double	inv_det;
	double	dx;
	double	dy;

	dx = cub->sprites->x - cub->player.pos.x;
	dy = cub->sprites->y - cub->player.pos.y;
	inv_det = 1.0 / (cub->player.plan.x * cub->player.dir.y \
		- cub->player.dir.x * cub->player.plan.y);
	*trans_x = inv_det * (cub->player.dir.y * dx - cub->player.dir.x * dy);
	*trans_y = inv_det * (cub->player.plan.x * dy - cub->player.plan.y * dx);
}

static void	put_sprite(t_cub3d *cub, int *z_coor)
{
	int	tex_x;
	int	tex_y;
	int x;
	int y;

	x = cub->sprites->start_x - 1;
	while (++x < cub->sprites->end_x)
	{
		if (x < 0)
			x = 0;
		else if (x >= WIDTH)
			break ;
		y = cub->sprites->start_y - 1;
		while (++y < cub->sprites->end_y && cub->sprites->height > z_coor[x])
		{
			if (y < 0)
				y = 0;
			else if (y >= WIDTH)
				break ;
			tex_x = (double)(x - cub->sprites->start_x) / \
				(cub->sprites->end_x - cub->sprites->start_x) \
				* cub->sprite_img.width;
			tex_y = (double)(y - cub->sprites->start_y) / \
				(cub->sprites->end_y - cub->sprites->start_y) \
				* cub->sprite_img.height;
			set_color(1, cub->sprite_img.__addr[cub->sprite_img.height \
				* tex_y + tex_x]);
			if (set_color(0, 0) != 0xff000000)
				my_mlx_pixel_put(x, y, &cub->img);
		}

	}
}

void	put_sprites(t_cub3d *cub, int *z_coor)
{
	double	trans_x;
	double	trans_y;
	int		screen_x;

	if (!is_visible(cub, cub->sprites->x, cub->sprites->y))
		return ;
	transform_sprite(cub, &trans_x, &trans_y);
	screen_x = (int)((WIDTH / 2) * (1 + trans_x / trans_y));
	cub->sprites->height = abs((int)(HEIGHT / trans_y));
	cub->sprites->width = abs((int)(HEIGHT / trans_y));

	cub->sprites->start_x = - cub->sprites->width / 2 + screen_x;
	cub->sprites->end_x = cub->sprites->width / 2 + screen_x ;
	cub->sprites->start_y = HEIGHT / 2 - cub->sprites->height / 2;
	cub->sprites->end_y = HEIGHT / 2 + cub->sprites->height / 2;
	if (trans_y >= 0)
		put_sprite(cub, z_coor);
}

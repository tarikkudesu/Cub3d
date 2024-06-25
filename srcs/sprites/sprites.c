/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:16:03 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 17:25:10 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	put_sprite_pixel(t_cub3d *cub, int x, int y)
{
	int	tex_x;
	int	tex_y;

	tex_x = (double)(x - cub->sprite->start_x) / \
		(cub->sprite->end_x - cub->sprite->start_x) \
		* cub->sprite_img[cub->frame].width;
	tex_y = (double)(y - cub->sprite->start_y) / \
		(cub->sprite->end_y - cub->sprite->start_y) \
		* cub->sprite_img[cub->frame].height;
	if (tex_x >= 0 && tex_x < cub->sprite_img[cub->frame].width && \
		tex_y >= 0 && tex_y < cub->sprite_img[cub->frame].height)
	{
		set_color(1, cub->sprite_img[cub->frame].__addr[\
			cub->sprite_img[cub->frame].height \
			* tex_y + tex_x]);
		if (set_color(0, 0) != 0xff000000)
			my_mlx_pixel_put(x, y, &cub->img);
	}
}

void	put_sprite(t_cub3d *cub, int *z_coor)
{
	int	x;
	int	y;

	x = cub->sprite->start_x - 1;
	while (++x < cub->sprite->end_x)
	{
		if (x < 0)
			x = 0;
		else if (x >= WIDTH)
			break ;
		y = cub->sprite->start_y - 1;
		while (++y < cub->sprite->end_y && cub->sprite->height > z_coor[x])
		{
			if (y < 0)
				y = 0;
			else if (y >= WIDTH)
				break ;
			put_sprite_pixel(cub, x, y);
		}
	}
}

void	put_sprites(t_cub3d *cub, int *z_coor)
{
	t_sprite	*sprite;
	int			i;

	i = 0;
	set_distance(cub);
	sprite = cub->sprites_list;
	while (sprite)
	{
		cub->sprite = sprite;
		if (set_sprite_data(cub))
			put_sprite(cub, z_coor);
		sprite = sprite->next;
	}
}

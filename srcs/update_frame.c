/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:00:29 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 19:18:58 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	set_color(bool flag, int value)
{
	static int	color;

	if (flag == true)
		color = value;
	return (color);
}

static void	update_map(t_cub3d *cub)
{
	int			x;
	int			y;

	x = -1;
	cub->frame++;
	if (cub->frame == 40)
		cub->frame = 0;
	while (++x < cub->map_height)
	{
		y = -1;
		while (++y < cub->map_width)
			cub->map[x][y].visited = false;
	}
}

static void	update_doors(t_cub3d *cub)
{
	t_door	*tmp;

	tmp = cub->doors;
	while (tmp)
	{
		if (tmp->ismoving == 1)
		{
			if (tmp->progress <= 1)
				tmp->progress += 0.02;
			else
			{
				tmp->progress = 1;
				tmp->ismoving = 0;
				tmp->isopen = 1;
			}
		}
		tmp = tmp->next;
	}
}

static void	put_background(t_cub3d *cub)
{
	int	w;
	int	h;

	w = -1;
	while (++w < WIDTH)
	{
		h = -1;
		set_color(1, rgb_to_hex(cub->ceiling_color));
		while (++h < HEIGHT / 2)
			my_mlx_pixel_put(w, h, &cub->img);
		set_color(1, rgb_to_hex(cub->floor_color));
		while (++h < HEIGHT)
			my_mlx_pixel_put(w, h, &cub->img);
	}
}

int	update_frame(void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	if (cub->mode == INTRO)
		mlx_put_image_to_window(cub->mlx.__mlx, \
			cub->mlx.__win, cub->mlx.__intro, 0, 0);
	else if (cub->mode == MENU)
		mlx_put_image_to_window(cub->mlx.__mlx, \
			cub->mlx.__win, cub->mlx.__menu, 0, 0);
	else if (cub->mode == GAME)
	{
		update_doors(cub);
		put_background(cub);
		update_map(cub);
		put_rays(cub);
		minimap(cub);
		mlx_put_image_to_window(cub->mlx.__mlx, \
			cub->mlx.__win, cub->img.__img, 0, 0);
	}
	return (0);
}

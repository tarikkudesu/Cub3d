/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:03:27 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/05 11:07:20 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	put_block(int x, int y, t_cub3d *cub)
{
	int	w;
	int	h;

	w = x - 1;
	while (++w < x + cub->wall_width)
	{
		h = y - 1;
		while (++h < y + cub->wall_width)
			minimap_pixel_put(w, h, &cub->img);
	}
}

static void	put_background(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 40;
	set_color(true, BACKGROUND);
	while (i < 240)
	{
		j = 40;
		while (j < 240)
			minimap_pixel_put(i, j++, &cub->img);
		i++;
	}
}

static void	put_minimap(t_cub3d *cub)
{
	int	x;
	int	y;
	int	x_n;
	int	y_n;

	x = -1;
	while (++x < cub->map_height)
	{
		y = -1;
		while (++y < cub->map_width)
		{
			if (is_wall(x, y) || is_door(x, y))
			{
				if (is_wall(x, y))
					set_color(true, WHITE);
				else
					set_color(true, CYAN);
				x_n = y;
				y_n = x;
				put_block((x_n - cub->player.pos.y) * cub->wall_width + 140, \
					(y_n - cub->player.pos.x) * cub->wall_width + 140, cub);
			}
		}
	}
}

static void	put_dir_rays(t_cub3d *cub)
{
	t_vect	start;
	t_vect	end;
	t_vect	dir;
	int		i;

	i = -1;
	start.x = 140;
	start.y = 140;
	set_color(true, CYAN);
	dir.x = -1 * cub->player.dir.y;
	dir.y = -1 * cub->player.dir.x;
	rotate_vector(&dir, M_PI);
	rotate_vector(&dir, -1 * PI_1 * 30);
	while (++i < 60)
	{
		end.x = start.x + 100 * dir.x;
		end.y = start.y + 100 * dir.y;
		draw_line(&start, &end);
		rotate_vector(&dir, PI_1);
	}
}

void	minimap(t_cub3d *cub)
{
	int	i;
	int	j;

	put_background(cub);
	put_minimap(cub);
	put_dir_rays(cub);
	i = 137;
	while (++i < 142)
	{
		j = 137;
		while (++j < 142)
			minimap_pixel_put(i, j, &cub->img);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:06:27 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 17:26:15 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(int x, int y, const t_image *img)
{
	int		*addr;
	int		pixel;

	addr = (int *)img->__addr;
	pixel = y * img->line_bytes / 4 + x;
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		addr[pixel] = set_color(false, 0);
}

void	lesser(int p, t_vect *a, t_vect *b, const t_image *img)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	x = a->x;
	y = a->y;
	while (++i < abs((int)(b->x - a->x)))
	{
		if (b->x - a->x < 0)
			x -= 1;
		else
			x += 1;
		if (p < 0)
			p = p + 2 * abs((int)(b->y - a->y));
		else
		{
			if (b->y - a->y < 0)
				y -= 1;
			else
				y += 1;
			p = p + 2 * abs((int)(b->y - a->y)) - 2 * abs((int)(b->x - a->x));
		}
		my_mlx_pixel_put(x, y, img);
	}
}

void	bigger(int p, t_vect *a, t_vect *b, const t_image *img)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	x = a->x;
	y = a->y;
	while (++i < abs((int)(b->y - a->y)))
	{
		if (b->y - a->y < 0)
			y -= 1;
		else
			y += 1;
		if (p < 0)
			p = p + 2 * abs((int)(b->x - a->x));
		else
		{
			if (b->x - a->x < 0)
				x -= 1;
			else
				x += 1;
			p = p + 2 * abs((int)(b->x - a->x)) - 2 * abs((int)(b->y - a->y));
		}
		my_mlx_pixel_put(x, y, img);
	}
}

void	draw_line(t_vect *a, t_vect *b, const t_image *img)
{
	my_mlx_pixel_put(a->x, a->y, img);
	if (abs((int)(b->x - a->x)) > abs((int)(b->y - a->y)))
		lesser(2 * abs((int)(b->y - a->y)) - \
			abs((int)(b->x - a->x)), a, b, img);
	else
		bigger(2 * abs((int)(b->x - a->x)) - \
			abs((int)(b->y - a->y)), a, b, img);
}

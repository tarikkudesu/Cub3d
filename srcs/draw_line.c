/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:06:27 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/27 09:10:31 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(int x, int y)
{
	t_cub3d	*cub;
	int		*addr;
	int		pixel;

	cub = get_cub(NULL);
	addr = (int *)cub->img.__addr;
	pixel = y * cub->img.line_bytes / 4 + x;
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		addr[pixel] = set_color(false, 0);
}

static void	lesser(int p, t_vect *a, t_vect *b)
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
		my_mlx_pixel_put(x, y);
	}
}

static void	bigger(int p, t_vect *a, t_vect *b)
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
		my_mlx_pixel_put(x, y);
	}
}

void	draw_line(t_vect *a, t_vect *b)
{
	my_mlx_pixel_put(a->x, a->y);
	if (abs((int)(b->x - a->x)) > abs((int)(b->y - a->y)))
		lesser(2 * abs((int)(b->y - a->y)) - \
			abs((int)(b->x - a->x)), a, b);
	else
		bigger(2 * abs((int)(b->x - a->x)) - \
			abs((int)(b->y - a->y)), a, b);
}

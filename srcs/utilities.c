/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:52:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/10 20:55:31 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

t_color	hex_to_rgb(int color)
{
	t_color	rgb;

	rgb.red = (color >> 16) & 255;
	rgb.green = (color >> 8) & 255;
	rgb.blue = (color >> 0) & 255;
	return (rgb);
}

int	rgb_to_hex(t_color rgb)
{
	return (rgb.blue | rgb.green << 8 | rgb.red << 16);
}


void	rotate_vector(t_vect *vector, double angle)
{
	double	tmp;

	tmp = vector->x;
	vector->x = tmp * cos(angle) - vector->y * sin(angle);
	vector->y = tmp * sin(angle) + vector->y * cos(angle);
}

bool	is_in_cercle(int x, int y)
{
	int	dx;
	int	dy;
	int	distance;
	
	dx = x - 140;
	dy = y - 140;
	distance = dx * dx + dy * dy;
	if (distance <= 10000)
		return (true);
	return (false);
}

void	minimap_pixel_put(int x, int y, const t_image *img)
{
	int		pixel;

	pixel = y * img->line_bytes / 4 + x;
	if (x < 240 && x >= 40 && y < 240 && y >= 40)
	{
		if (is_in_cercle(x, y))
			img->__addr[pixel] = set_color(false, 0);
	}
}

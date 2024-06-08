/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:58:23 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/08 10:05:48 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_color	to_rgb(int color)
{
	t_color	rgb;

	rgb.red = (color >> 16) & 255;
	rgb.green = (color >> 8) & 255;
	rgb.blue = (color >> 0) & 255;
	return (rgb);
}

int	from_rgb(t_color rgb)
{
	return (rgb.blue | rgb.green << 8 | rgb.red << 16);
}

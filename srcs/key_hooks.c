/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:53:35 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/03 21:40:02 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_key(int key, t_cub3d *cub)
{
	if (key == ESC || key == ESC_L)
		exit_program(cub);
	else if (key == SPACE || key == SPACE_L)
		cub->panel = 0;
	else if (key == W || key == W_L)
	{
		cub->player.x_pos += cub->player.pdx;
		cub->player.y_pos += cub->player.pdy;
	}
	else if (key == S || key == S_L)
	{
		cub->player.x_pos -= cub->player.pdx;
		cub->player.y_pos -= cub->player.pdy;
	}
	else if (key == D || key == D_L)
	{
		cub->player.angle += 0.1;
		if (cub->player.angle > 2 * M_PI)
			cub->player.angle -= 2 * M_PI;
		cub->player.pdx = cos(cub->player.angle) * 8;
		cub->player.pdy = sin(cub->player.angle) * 8;
	}
	else if (key == A || key == A_L)
	{
		cub->player.angle -= 0.1;
		if (cub->player.angle < 0)
			cub->player.angle += 2 * M_PI;
		cub->player.pdx = cos(cub->player.angle) * 8;
		cub->player.pdy = sin(cub->player.angle) * 8;
	}
	// printf("%f\n", cub->ray.angle);
	// printf("%d\n", key);
	return (0);
}

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
	if (key == ESC)
		exit_program(cub);
	else if (key == SPACE)
		cub->panel = 0;
	else if (key == W)
	{
		cub->player.x_pos += 8 * cos(cub->player.angle);
		cub->player.y_pos += 8 * sin(cub->player.angle);
	}
	else if (key == S)
	{
		cub->player.x_pos -= 8 * cos(cub->player.angle);
		cub->player.y_pos -= 8 * sin(cub->player.angle);
	}
	else if (key == D)
	{
		cub->player.x_pos += 8 * cos(cub->player.angle);
		cub->player.y_pos -= 8 * sin(cub->player.angle);
	}
	else if (key == A)
	{
		cub->player.x_pos -= 8 * cos(cub->player.angle);
		cub->player.y_pos += 8 * sin(cub->player.angle);
	}
	else if (key == RIGHT)
		cub->player.angle += 0.05;
	else if (key == LEFT)
		cub->player.angle -= 0.05;
	// printf("%f\n", cub->ray.angle);
	// printf("%d\n", key);
	return (0);
}

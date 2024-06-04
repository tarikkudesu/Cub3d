/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:02:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/04 21:46:22 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	initialize_data(t_cub3d *cub)
{
	if (Z) {atexit(leaks);}
	cub->panel = 1;
	cub->heap = NULL;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->player.x_pos = 32 + 64;
	cub->player.y_pos = 32 + 64;
	cub->player.angle = M_PI;
	cub->wall_width = 32;
	cub->ray.distance = 400;
	cub->ray.angle = M_PI;
	cub->map_width = mapWidth;
	cub->map_height = mapHeight;
	cub->player.pdx = cos(cub->player.angle) * 12;
	cub->player.pdy = sin(cub->player.angle) * 12;
}

int	main()
{
	t_cub3d	cub;

	initialize_data(&cub);
	if (init_window(&cub))
		return (0);
}
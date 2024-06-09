/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:02:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/09 17:40:13 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	initialize_data(t_cub3d *cub)
{
	if (Z) {atexit(leaks);}
	cub->panel = 1;
	cub->heap = NULL;
	cub->wall_width = 20;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->player.pos.x = 2;
	cub->player.pos.y = 7;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.plan.x = 0;
	cub->player.pole = EASTH;
	cub->player.plan.y = 0.66;
	cub->map_width = mapWidth;
	cub->map_height = mapHeight;
	cub->info.ceiling_color = to_rgb(SKY);
	cub->info.floor_color = to_rgb(FLOOR);
}

int	main()
{
	t_cub3d	cub;

	initialize_data(&cub);
	if (init_window(&cub))
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:23:45 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 10:27:07 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_data(t_cub3d *cub)
{
	t_door		*door;
	t_sprite	*sprite;
	int	x;
	int	y;

	y = -1;
	while (++y < cub->map_height)
	{
		x = -1;
		while (++x < cub->map_width)
		{
			if (cub->map[y][x].door)
				new_door(cub, x, y);
			else if (cub->map[y][x].v == 3)
				new_sprite(cub, x, y);
		}
	}
	set_player_data(cub);
}

void	initialize_data(t_cub3d *cub)
{
	// if (Z) {atexit(leaks);}
	cub->gun = 0;
	cub->button = 0;
	cub->heap = NULL;
	cub->map = NULL;
	cub->doors = NULL;
	cub->line = NULL;
	cub->sprites = NULL;
	cub->mode = INTRO;
	cub->wall_width = 10;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->player.pos.x = 1.5;
	cub->player.pos.y = 1.5;
	cub->player.dir.x = 0;
	cub->player.dir.y = 1;
	cub->player.plan.x = -0.66;
	cub->player.plan.y = 0;
	cub->map_width = 0;
	cub->map_height = 0;
}

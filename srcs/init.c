/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:23:45 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 11:27:09 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_player_data(t_cub3d *cub)
{
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	if (cub->player.pole == WEST)
		rotate_vector(&cub->player.dir, M_PI);
	else if (cub->player.pole == NORTH)
		rotate_vector(&cub->player.dir, M_PI / 2);
	else if (cub->player.pole == NORTH)
		rotate_vector(&cub->player.dir, - M_PI / 2);
	cub->player.plan = cub->player.dir;
	rotate_vector(&cub->player.plan, - M_PI / 2);
}

void	set_data(t_cub3d *cub)
{
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
			else if (cub->map[y][x].v == 'N' || cub->map[y][x].v == 'E' \
			|| cub->map[y][x].v == 'W' || cub->map[y][x].v == 'S')
			{
				cub->player.pole = cub->map[y][x].v;
				cub->player.pos.x = y + 0.5;
				cub->player.pos.y = x + 0.5;
				printf("%f %f \n", cub->player.pos.x, cub->player.pos.y);
			}
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
	cub->player.pole = WEST;
	cub->wall_width = 10;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->player.pos.x = 1.5;
	cub->player.pos.y = 1.5;
	cub->map_width = 0;
	cub->map_height = 0;
}

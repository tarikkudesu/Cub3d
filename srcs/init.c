/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:23:45 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 11:09:12 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_player_data(t_cub3d *cub)
{
	cub->player.dir.x = 0;
	cub->player.dir.y = 1;
	cub->player.plan.x = -0.66;
	cub->player.plan.y = 0;
	if (cub->player.pole == WEST)
	{
		rotate_vector(&cub->player.dir, - M_PI / 2);
		rotate_vector(&cub->player.plan, - M_PI / 2);
	}
	else if (cub->player.pole == NORTH)
	{
		rotate_vector(&cub->player.dir, M_PI);
		rotate_vector(&cub->player.plan, M_PI);
	}
	else if (cub->player.pole == EASTH)
	{
		rotate_vector(&cub->player.dir, M_PI / 2);
		rotate_vector(&cub->player.plan, M_PI / 2);
	}
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
			}
		}
	}
	set_player_data(cub);
}



void	initialize_data(t_cub3d *cub)
{
	if (Z) {atexit(leaks);}
	cub->button = 0;
	cub->heap = NULL;
	cub->map = NULL;
	cub->doors = NULL;
	cub->line = NULL;
	cub->sprite = NULL;
	cub->sprites_list = NULL;
	cub->mode = INTRO;
	cub->frame = 0;
	cub->map_height = 0;
	cub->map_width = 0;
	cub->player_nbr = 0;
	cub->imgcontainer = NULL;
	cub->wall_width = 10;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->mlx.__mlx = NULL;
	cub->mlx.__win = NULL;
	cub->mlx.__menu = NULL;
	cub->mlx.__intro = NULL;
	cub->img.__img = NULL;
}

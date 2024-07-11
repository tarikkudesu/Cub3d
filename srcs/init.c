/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:23:45 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/11 20:14:23 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_player_data(t_cub3d *cub)
{
	cub->player.dir.x = -1;
	cub->player.dir.y = 0;
	cub->player.plan.x = 0;
	cub->player.plan.y = 0.66;
	if (cub->player.pole == WEST)
	{
		rotate_vector(&cub->player.dir, M_PI / 2);
		rotate_vector(&cub->player.plan, M_PI / 2);
	}
	else if (cub->player.pole == SOUTH)
	{
		rotate_vector(&cub->player.dir, M_PI);
		rotate_vector(&cub->player.plan, M_PI);
	}
	else if (cub->player.pole == EASTH)
	{
		rotate_vector(&cub->player.dir, -1 * M_PI / 2);
		rotate_vector(&cub->player.plan, -1 * M_PI / 2);
	}
}

void	set_data(t_cub3d *cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < cub->map_height)
	{
		y = -1;
		while (++y < cub->map_width)
		{
			if (cub->map[x][y].v == 1)
				cub->map[x][y].wall = true;
			else if (cub->map[x][y].v == 2)
				new_door(cub, x, y);
			else if (cub->map[x][y].v == 3)
				new_sprite(cub, x, y);
			else if (cub->map[x][y].v == 'N' || cub->map[x][y].v == 'E' \
			|| cub->map[x][y].v == 'W' || cub->map[x][y].v == 'S')
			{
				cub->player.pole = cub->map[x][y].v;
				cub->player.pos.x = x + 0.5;
				cub->player.pos.y = y + 0.5;
			}
		}
	}
	set_player_data(cub);
}

void	initialize_data(t_cub3d *cub)
{
	cub->keys.space = false;
	cub->keys.right = false;
	cub->keys.left = false;
	cub->keys.esc = false;
	cub->keys.q = false;
	cub->keys.w = false;
	cub->keys.d = false;
	cub->keys.s = false;
	cub->keys.a = false;
	cub->frame = 0;
	cub->button = 0;
	cub->map = NULL;
	cub->heap = NULL;
	cub->line = NULL;
	cub->doors = NULL;
	cub->mode = INTRO;
	cub->sprite = NULL;
	cub->map_width = 0;
	cub->map_height = 0;
	cub->player_nbr = 0;
	cub->wall_width = 10;
	cub->mlx.__mlx = NULL;
	cub->img.__img = NULL;
	cub->mlx.__win = NULL;
	cub->img.__addr = NULL;
	cub->mlx.__menu = NULL;
	cub->mlx.__intro = NULL;
	cub->imgcontainer = NULL;
	cub->sprites_list = NULL;
}

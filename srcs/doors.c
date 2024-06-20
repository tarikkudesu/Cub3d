/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:58:23 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/10 20:53:54 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_door(t_cub3d *cub, int x, int y)
{
	if (x >= 0 && x < cub->map_height && y >= 0 && y < cub->map_width)
		return (cub->mapS[x][y].door);
	return (false);
}

static void	open_door(t_cub3d *cub, int d_x, int d_y)
{
	t_door	*tmp;

	tmp = cub->doors;
	while (tmp)
	{
		if (tmp->x == d_x && tmp->y == d_y)
			tmp->ismoving = 1;
		tmp = tmp->next;
	}
}

void	open_doors(t_cub3d *cub)
{
	int		i;
	int		p_x;
	int		p_y;

	i = 0;
	p_x = cub->player.pos.x;
	p_y = cub->player.pos.y;
	while (++i <= 2)
	{
		if (cub->player.pole == NORTH && is_door(cub, p_x, p_y - i))
			open_door(cub, p_x, p_y - i);
		else if (cub->player.pole == SOUTH && is_door(cub, p_x, p_y + i))
			open_door(cub, p_x, p_y + i);
		else if (cub->player.pole == WEST && is_door(cub, p_x - i, p_y))
			open_door(cub, p_x - i, p_y);
		else if (cub->player.pole == EASTH && is_door(cub, p_x + i, p_y))
			open_door(cub, p_x + i, p_y);
	}
}


void	update_doors(t_cub3d *cub)
{
	t_door	*tmp;

	tmp = cub->doors;
	while (tmp)
	{
		if (tmp->ismoving == 1)
		{
			if (tmp->progress <= 1)
				tmp->progress += 0.06;
			else
			{
				tmp->progress = 1;
				tmp->ismoving = 0;
				tmp->isopen = 1;
			}
		}
		tmp = tmp->next;
	}
}

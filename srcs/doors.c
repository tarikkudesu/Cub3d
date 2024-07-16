/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:19:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/12 10:27:46 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	open_door(t_cub3d *cub, int d_x, int d_y)
{
	t_door	*tmp;

	tmp = cub->doors;
	while (tmp)
	{
		if (tmp->x == d_x && tmp->y == d_y && !tmp->isopen)
		{
			if (!tmp->isclosing && !tmp->isopening)
				tmp->isopening = true;
		}
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
		if (cub->player.pole == NORTH && is_door(p_x - i, p_y))
			open_door(cub, p_x - i, p_y);
		else if (cub->player.pole == SOUTH && is_door(p_x + i, p_y))
			open_door(cub, p_x + i, p_y);
		else if (cub->player.pole == WEST && is_door(p_x, p_y - i))
			open_door(cub, p_x, p_y - i);
		else if (cub->player.pole == EAST && is_door(p_x, p_y + i))
			open_door(cub, p_x, p_y + i);
	}
}

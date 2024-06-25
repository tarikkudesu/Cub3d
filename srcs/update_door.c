/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:58:39 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 14:05:10 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	timer(t_door *door)
{
	door->timer++;
	if (door->timer == 100)
	{
		door->ismoving = 1;
		door->timer = 0;
	}
}

static void	opening_door(t_door *door)
{
	if (door->progress <= 1)
		door->progress += 0.02;
	else
	{
		door->progress = 1;
		door->ismoving = 0;
		door->isopen = 1;
	}
}

static void	closing_door(t_cub3d *cub, t_door *door)
{
	if (floor(cub->player.pos.x) == door->x \
		&& floor(cub->player.pos.y) == door->y)
		return ;
	if (door->progress >= 0)
		door->progress -= 0.02;
	else
	{
		door->progress = 0;
		door->ismoving = 0;
		door->isopen = 0;
	}
}

void	update_doors(t_cub3d *cub)
{
	t_door	*tmp;

	tmp = cub->doors;
	while (tmp)
	{
		if (tmp->isopen && tmp->ismoving == 0)
			timer(tmp);
		if (tmp->isopen && tmp->ismoving == 1)
			closing_door(cub, tmp);
		else if (tmp->ismoving == 1)
			opening_door(tmp);
		tmp = tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:58:39 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/02 21:37:15 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	timer(t_cub3d *cub, t_door *door)
{
	if (floor(cub->player.pos.x) == door->x \
		&& floor(cub->player.pos.y) == door->y)
		return ;
	door->timer++;
	if (door->timer == 100)
	{
		door->isclosing = true;
		door->isopen = false;
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
		door->isopening = false;
		door->isopen = true;
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
		door->isclosing = false;
		door->isopen = false;
	}
}

void	update_doors(t_cub3d *cub)
{
	t_door	*tmp;

	tmp = cub->doors;
	while (tmp)
	{
		if (tmp->isopen)
			timer(cub, tmp);
		if (tmp->isclosing == true)
			closing_door(cub, tmp);
		if (tmp->isopening == true)
			opening_door(tmp);
		tmp = tmp->next;
	}
}

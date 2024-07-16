/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:55:28 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/16 11:47:09 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	move(t_cub3d *cub, int x, int y)
{
	t_door	*tmp;

	tmp = cub->doors;
	if (is_door(x, y))
	{
		while (tmp)
		{
			if (tmp->x == x && tmp->y == y)
			{
				if (!tmp->isopen)
					return (true);
				else
					return (false);
			}
			tmp = tmp->next;
		}
	}
	else if (is_wall(x, y))
		return (true);
	return (false);
}

void	north(t_cub3d *cub, t_vect *new_pos)
{
	if (!move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)))
		cub->player.pos.x = new_pos->x;
	else if (new_pos->x >= floor(cub->player.pos.x) + 0.1)
		cub->player.pos.x = new_pos->x;
	if (new_pos->y < cub->player.pos.y)
	{
		if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1))
			cub->player.pos.y = new_pos->y;
		else if (new_pos->y >= floor(cub->player.pos.y) + 0.1)
			cub->player.pos.y = new_pos->y;
	}
	else
	{
		if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1))
			cub->player.pos.y = new_pos->y;
		else if (new_pos->y <= floor(cub->player.pos.y) + 1 - 0.1)
			cub->player.pos.y = new_pos->y;
	}
}

void	south(t_cub3d *cub, t_vect *new_pos)
{
	if (!move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)))
		cub->player.pos.x = new_pos->x;
	else if (new_pos->x <= floor(cub->player.pos.x) + 1 - 0.1)
		cub->player.pos.x = new_pos->x;
	if (new_pos->y < cub->player.pos.y)
	{
		if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1))
			cub->player.pos.y = new_pos->y;
		else if (new_pos->y >= floor(cub->player.pos.y) + 0.1)
			cub->player.pos.y = new_pos->y;
	}
	else
	{
		if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1))
			cub->player.pos.y = new_pos->y;
		else if (new_pos->y <= floor(cub->player.pos.y) + 1 - 0.1)
			cub->player.pos.y = new_pos->y;
	}
}

void	east(t_cub3d *cub, t_vect *new_pos)
{
	if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1))
		cub->player.pos.y = new_pos->y;
	else if (new_pos->y <= floor(cub->player.pos.y) + 1 - 0.1)
		cub->player.pos.y = new_pos->y;
	if (new_pos->x < cub->player.pos.x)
	{
		if (!move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)))
			cub->player.pos.x = new_pos->x;
		else if (new_pos->x >= floor(cub->player.pos.x) + 0.1)
			cub->player.pos.x = new_pos->x;
	}
	else
	{
		if (!move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)))
			cub->player.pos.x = new_pos->x;
		else if (new_pos->x <= floor(cub->player.pos.x) + 1 - 0.1)
			cub->player.pos.x = new_pos->x;
	}
}

void	west(t_cub3d *cub, t_vect *new_pos)
{
	if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1))
		cub->player.pos.y = new_pos->y;
	else if (new_pos->y >= floor(cub->player.pos.y) + 0.1)
		cub->player.pos.y = new_pos->y;
	if (new_pos->x < cub->player.pos.x)
	{
		if (!move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)))
			cub->player.pos.x = new_pos->x;
		else if (new_pos->x >= floor(cub->player.pos.x) + 0.1)
			cub->player.pos.x = new_pos->x;
	}
	else
	{
		if (!move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)))
			cub->player.pos.x = new_pos->x;
		else if (new_pos->x <= floor(cub->player.pos.x) + 1 - 0.1)
			cub->player.pos.x = new_pos->x;
	}
}

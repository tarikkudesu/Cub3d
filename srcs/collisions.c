/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:19:59 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/11 19:35:09 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// extern int worldMap[mapWidth][mapHeight];

bool	move(t_cub3d *cub, int x, int y)
{
	t_door	*tmp;

	tmp = cub->doors;
	if (is_wall(cub, x, y))
		return (true);
	if (is_door(cub, x, y))
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
	return (false);
}

void	north(t_cub3d *cub, t_vect *new_pos)
{
	if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1))
		cub->player.pos.y = new_pos->y;
	if (move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1) && \
		new_pos->y >= floor(cub->player.pos.y) + 0.2)
		cub->player.pos.y = new_pos->y;
	if (new_pos->x < cub->player.pos.x)
	{
		if (!move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)))
			cub->player.pos.x = new_pos->x;
		if (move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)) && \
			new_pos->x >= floor(cub->player.pos.x) + 0.2)
			cub->player.pos.x = new_pos->x;
	}
	else
	{
		if (!move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)))
			cub->player.pos.x = new_pos->x;
		if (move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)) && \
			new_pos->x <= floor(cub->player.pos.x) + 1 - 0.2)
			cub->player.pos.x = new_pos->x;
	}
}

void	easth(t_cub3d *cub, t_vect *new_pos)
{
	if (!move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)))
		cub->player.pos.x = new_pos->x;
	if (move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)) && \
		new_pos->x >= floor(cub->player.pos.x) + 0.2)
		cub->player.pos.x = new_pos->x;
	if (new_pos->y < cub->player.pos.y)
	{
		if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1))
			cub->player.pos.y = new_pos->y;
		if (move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1) && \
			new_pos->y >= floor(cub->player.pos.y) + 0.2)
			cub->player.pos.y = new_pos->y;
	}
	else
	{
		if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1))
			cub->player.pos.y = new_pos->y;
		if (move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1) && \
			new_pos->y <= floor(cub->player.pos.y) + 1 - 0.2)
			cub->player.pos.y = new_pos->y;
	}
}

void	south(t_cub3d *cub, t_vect *new_pos)
{
	if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1))
		cub->player.pos.y = new_pos->y;
	if (move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1) && \
		new_pos->y <= floor(cub->player.pos.y) + 1 - 0.2)
		cub->player.pos.y = new_pos->y;
	if (new_pos->x < cub->player.pos.x)
	{
		if (!move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)))
			cub->player.pos.x = new_pos->x;
		if (move(cub, floor(cub->player.pos.x) - 1, floor(cub->player.pos.y)) && \
			new_pos->x >= floor(cub->player.pos.x) + 0.2)
			cub->player.pos.x = new_pos->x;
	}
	else
	{
		if (!move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)))
			cub->player.pos.x = new_pos->x;
		if (move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)) && \
			new_pos->x <= floor(cub->player.pos.x) + 1 - 0.2)
			cub->player.pos.x = new_pos->x;
	}
}

void	west(t_cub3d *cub, t_vect *new_pos)
{
	if (!move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)))
		cub->player.pos.x = new_pos->x;
	else if (move(cub, floor(cub->player.pos.x) + 1, floor(cub->player.pos.y)) \
		&& new_pos->x <= floor(cub->player.pos.x) + 1 - 0.2)
		cub->player.pos.x = new_pos->x;
	if (new_pos->y < cub->player.pos.y)
	{
		if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1))
			cub->player.pos.y = new_pos->y;
		else if (move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) - 1) \
			&& new_pos->y >= floor(cub->player.pos.y) + 0.2)
			cub->player.pos.y = new_pos->y;
	}
	else
	{
		if (!move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1))
			cub->player.pos.y = new_pos->y;
		else if (move(cub, floor(cub->player.pos.x), floor(cub->player.pos.y) + 1) \
			&& new_pos->y <= floor(cub->player.pos.y) + 1 - 0.2)
			cub->player.pos.y = new_pos->y;
	}
}

void	check_for_wall(t_cub3d *cub, t_vect *rotated)
{
	t_vect	new_pos;

	new_pos.x = cub->player.pos.x + rotated->x * 0.4;
	new_pos.y = cub->player.pos.y + rotated->y * 0.4;
	if (fabs(rotated->x) < fabs(rotated->y))
	{
		if (rotated->y < 0)
			north(cub, &new_pos);
		else
			south(cub, &new_pos);
	}
	else
	{
		if (rotated->x < 0)
			easth(cub, &new_pos);
		else
			west(cub, &new_pos);
	}
}

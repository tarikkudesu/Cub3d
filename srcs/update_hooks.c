/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:19:21 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/16 11:51:53 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	check_for_wall(t_cub3d *cub, t_vect *rotated)
{
	t_vect	new_pos;

	new_pos.x = cub->player.pos.x + rotated->x * 0.1;
	new_pos.y = cub->player.pos.y + rotated->y * 0.1;
	if (fabs(rotated->x) > fabs(rotated->y))
	{
		if (rotated->x < 0)
			north(cub, &new_pos);
		else
			south(cub, &new_pos);
	}
	else
	{
		if (rotated->y > 0)
			east(cub, &new_pos);
		else
			west(cub, &new_pos);
	}
}

static void	rotate_player(t_cub3d *cub)
{
	if (cub->keys.right)
	{
		rotate_vector(&cub->player.dir, -0.0174533 * 2);
		rotate_vector(&cub->player.plan, -0.0174533 * 2);
	}
	else if (cub->keys.left)
	{
		rotate_vector(&cub->player.dir, 0.0174533 * 2);
		rotate_vector(&cub->player.plan, 0.0174533 * 2);
	}
	set_direction(cub);
}

void	move_player(t_cub3d *cub)
{
	t_vect	rotated;

	rotated.x = cub->player.dir.x;
	rotated.y = cub->player.dir.y;
	if (cub->keys.w)
		rotate_vector(&rotated, 0);
	else if (cub->keys.s)
		rotate_vector(&rotated, M_PI);
	else if (cub->keys.a)
		rotate_vector(&rotated, M_PI / 2);
	else if (cub->keys.d)
		rotate_vector(&rotated, -1 * M_PI / 2);
	check_for_wall(cub, &rotated);
}

void	update_hooks(t_cub3d *cub)
{
	if (cub->keys.w || cub->keys.s || cub->keys.d || cub->keys.a)
		move_player(cub);
	if (cub->keys.right || cub->keys.left)
		rotate_player(cub);
	if (cub->keys.space)
		open_doors(cub);
}

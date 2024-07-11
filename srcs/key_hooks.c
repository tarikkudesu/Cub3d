/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:53:19 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/11 21:00:19 by tamehri          ###   ########.fr       */
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
		if (rotated->x > 0)
			north(cub, &new_pos);
		else
			south(cub, &new_pos);
	}
	else
	{
		if (rotated->y > 0)
			easth(cub, &new_pos);
		else
			west(cub, &new_pos);
	}
}

void	rotate_player(t_cub3d *cub)
{
	if (cub->keys.right)
	{
		rotate_vector(&cub->player.dir, -0.0174533 * 3);
		rotate_vector(&cub->player.plan, -0.0174533 * 3);
	}
	else if (cub->keys.left)
	{
		rotate_vector(&cub->player.dir, 0.0174533 * 3);
		rotate_vector(&cub->player.plan, 0.0174533 * 3);
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

int	key_up(int key, t_cub3d *cub)
{
	if (key == SPACE)
		cub->keys.space = false;
	else if (key == RIGHT)
		cub->keys.right = false;
	else if (key == LEFT)
		cub->keys.left = false;
	else if (key == W)
		cub->keys.w = false;
	else if (key == D)
		cub->keys.d = false;
	else if (key == S)
		cub->keys.s = false;
	else if (key == A)
		cub->keys.a = false;
	return 0;
}

int	key_down(int key, t_cub3d *cub)
{
	if (key == Q)
		exit_program(cub);
	else if (key == SPACE && cub->mode == INTRO && cub->button == 0)
		return (cub->mode = GAME, 0);
	else if (key == ESC && cub->mode == MENU && cub->button == 0)
		cub->mode = GAME;
	else if (key == ESC && cub->mode == GAME && cub->button == 0)
		cub->mode = MENU;
	if (cub->mode == INTRO || cub->mode == MENU)
		return (0);
	cub->keys.space = (key == SPACE);
	cub->keys.right = (key == RIGHT);
	cub->keys.left = (key == LEFT);
	cub->keys.w = (key == W);
	cub->keys.d = (key == D);
	cub->keys.s = (key == S);
	cub->keys.a = (key == A);
	return 0;
}

// int	handle_key(int key, t_cub3d *cub)
// {
// 	if (key == W || key == S || key == D || key == A)
// 		move_player(key, cub);
// 	else if (key == RIGHT || key == LEFT)
// 		rotate_player(key, cub);
// 	else if (key == SPACE)
// 		open_doors(cub);
// 	return (0);
// }

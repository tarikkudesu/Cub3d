/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:53:19 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 15:43:42 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	check_for_wall(t_cub3d *cub, t_vect *rotated)
{
	t_vect	new_pos;

	new_pos.x = cub->player.pos.x + rotated->x * 0.2;
	new_pos.y = cub->player.pos.y + rotated->y * 0.2;
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

static void	rotate_player(int key, t_cub3d *cub)
{
	if (key == RIGHT)
	{
		rotate_vector(&cub->player.dir, -0.0174533 * 4);
		rotate_vector(&cub->player.plan, -0.0174533 * 4);
	}
	else if (key == LEFT)
	{
		rotate_vector(&cub->player.dir, 0.0174533 * 4);
		rotate_vector(&cub->player.plan, 0.0174533 * 4);
	}
	set_direction(cub);
}

void	move_player(int key, t_cub3d *cub)
{
	t_vect	rotated;

	rotated.x = cub->player.dir.x;
	rotated.y = cub->player.dir.y;
	if (key == W)
		rotate_vector(&rotated, 0);
	else if (key == S)
		rotate_vector(&rotated, M_PI);
	else if (key == A)
		rotate_vector(&rotated, M_PI / 2);
	else if (key == D)
		rotate_vector(&rotated, - M_PI / 2);
	check_for_wall(cub, &rotated);
}

int	handle_key(int key, t_cub3d *cub)
{
	if (key == Q)
		exit_program(cub);
	else if (key == SPACE && cub->mode == INTRO && cub->button == 0) {
		cub->mode = GAME; return (0); }
	else if (key == ESC && cub->mode == MENU && cub->button == 0)
		cub->mode = GAME;
	else if (key == ESC && cub->mode == GAME && cub->button == 0)
		cub->mode = MENU;
	if (cub->mode == INTRO || cub->mode == MENU)
		return (0);
	if (key == W || key == S || key == D || key == A)
		move_player(key, cub);
	else if (key == RIGHT || key == LEFT)
		rotate_player(key, cub);
	else if (key == SPACE)
		open_doors(cub);
	return (0);
}
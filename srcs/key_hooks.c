/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:53:35 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/11 22:41:08 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	check_for_wall(t_cub3d *cub, t_vect *rotated)
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

void	move_player(int key, t_cub3d *cub)
{
	t_vect	rotated;

	rotated.x = cub->player.dir.x;
	rotated.y = cub->player.dir.y;
	if (key == W || key == W_L)
		rotate_vector(&rotated, 0);
	else if (key == S || key == S_L)
		rotate_vector(&rotated, M_PI);
	else if (key == A || key == A_L)
		rotate_vector(&rotated, - M_PI / 2);
	else if (key == D || key == D_L)
		rotate_vector(&rotated, M_PI / 2);
	check_for_wall(cub, &rotated);
}

static void	rotate_player(int key, t_cub3d *cub)
{
	if (key == RIGHT || key == RIGHT_L)
	{
		rotate_vector(&cub->player.dir, 0.0174533 * 4);
		rotate_vector(&cub->player.plan, 0.0174533 * 4);
	}
	else if (key == LEFT || key == LEFT_L)
	{
		rotate_vector(&cub->player.dir, -0.0174533 * 4);
		rotate_vector(&cub->player.plan, -0.0174533 * 4);
	}
	if (fabs(cub->player.dir.x) < fabs(cub->player.dir.y))
	{
		if (cub->player.dir.y < 0)
			cub->player.pole = NORTH;
		else
			cub->player.pole = SOUTH;
	}
	else
	{
		if (cub->player.dir.x < 0)
			cub->player.pole = WEST;
		else
			cub->player.pole = EASTH;
	}
}

int	handle_key(int key, t_cub3d *cub)
{
	if (key == Q || key == Q_L)
		exit_program(cub);
	else if ((key == SPACE || key == SPACE_L) && cub->mode == INTRO && cub->button == 0) {
		cub->mode = GAME; return (0); }
	else if ((key == ESC || key == ESC_L) && cub->mode == MENU && cub->button == 0)
		cub->mode = GAME;
	else if ((key == ESC || key == ESC_L) && cub->mode == GAME && cub->button == 0)
		cub->mode = MENU;
	if (cub->mode == INTRO || cub->mode == MENU)
		return (0);
	if (key == W || key == W_L \
			|| key == S || key == S_L \
			|| key == D || key == D_L \
			|| key == A || key == A_L)
		move_player(key, cub);
	else if (key == RIGHT || key == RIGHT_L \
			|| key == LEFT || key == LEFT_L)
		rotate_player(key, cub);
	else if (key == E || key == E_L)
		cub->gun = 1;
	else if (key == SPACE || key == SPACE_L)
		open_doors(cub);
	return (0);
}

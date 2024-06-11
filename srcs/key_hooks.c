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

void	rotate_player(int key, t_cub3d *cub)
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
	if (fabs(cub->player.dir.x) < fabs(cub->player.dir.y)) // ------------------------- you might need this so keep it, if not remove it
	{
		if (cub->player.dir.y < 0)
			cub->player.pole = NORTH;
		else
			cub->player.pole = SOUTH;
	}
	else
	{
		if (cub->player.dir.x < 0)
			cub->player.pole = EASTH;
		else
			cub->player.pole = WEST;
	}
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
	if (key == W || key == W_L \
			|| key == S || key == S_L \
			|| key == D || key == D_L \
			|| key == A || key == A_L)
			move_player(key, cub);
	else if (key == RIGHT || key == RIGHT_L \
			|| key == LEFT || key == LEFT_L)
			rotate_player(key, cub);
	else if (key == E)
		cub->gun = 1;
	else if (key == SPACE)
		cub->doors->isopen = 1;
	return (0);
}

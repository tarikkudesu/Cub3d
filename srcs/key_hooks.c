/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:53:35 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/07 20:42:44 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_vector(t_vect *vector, double angle)
{
	double	tmp;

	tmp = vector->x;
	vector->x = tmp * cos(angle) - vector->y * sin(angle);
	vector->y = tmp * sin(angle) + vector->y * cos(angle);
}

void	move_player(int key, t_cub3d *cub)
{
	t_vect	rotated;

	rotated.x = cub->player.dir.x;
	rotated.y = cub->player.dir.y;
	if (key == W || key == W_L)
	{
		cub->player.pos.x += cub->player.dir.x * 0.2;
		cub->player.pos.y += cub->player.dir.y * 0.2;
	}
	else if (key == S || key == S_L)
	{
		cub->player.pos.x -= cub->player.dir.x * 0.2;
		cub->player.pos.y -= cub->player.dir.y * 0.2;
	}
	else if (key == D || key == D_L)
	{
		rotate_vector(&rotated, M_PI / 2);
		cub->player.pos.x -= rotated.x * 0.2;
		cub->player.pos.y -= rotated.y * 0.2;
	}
	else if (key == A || key == A_L)
	{
		rotate_vector(&rotated, - M_PI / 2);
		cub->player.pos.x -= rotated.x * 0.2;
		cub->player.pos.y -= rotated.y * 0.2;
	}
}

void	rotate_player(int key, t_cub3d *cub)
{
	if (key == RIGHT || key == RIGHT_L)
	{
		rotate_vector(&cub->player.dir, -0.0174533 * 2);
		rotate_vector(&cub->player.plan, -0.0174533 * 2);
	}
	else if (key == LEFT || key == LEFT_L)
	{
		rotate_vector(&cub->player.dir, 0.0174533 * 2);
		rotate_vector(&cub->player.plan, 0.0174533 * 2);
	}
}

int	handle_key(int key, t_cub3d *cub)
{
	if (key == ESC || key == ESC_L)
		exit_program(cub);
	else if (key == SPACE || key == SPACE_L)
		cub->panel = GAME;
	else if (key == W || key == W_L \
			|| key == S || key == S_L \
			|| key == D || key == D_L \
			|| key == A || key == A_L)
			move_player(key, cub);
	else if (key == RIGHT || key == RIGHT_L \
			|| key == LEFT || key == LEFT_L)
			rotate_player(key, cub);
	// printf("Dir : (%f, %f), Camera : (%f, %f)\n", cub->player.dir.x, cub->player.dir.y, cub->player.plan.x, cub->player.plan.y);
	return (0);
}

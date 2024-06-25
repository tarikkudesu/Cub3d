/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:57:46 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 20:09:06 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_direction(t_cub3d *cub)
{
	if (fabs(cub->player.dir.x) < fabs(cub->player.dir.y))
	{
		if (cub->player.dir.y < 0)
			cub->player.pole = WEST;
		else
			cub->player.pole = EASTH;
	}
	else
	{
		if (cub->player.dir.x < 0)
			cub->player.pole = NORTH;
		else
			cub->player.pole = SOUTH;
	}
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_cub3d	*cub;

	(void)x;
	(void)y;
	cub = (t_cub3d *)param;
	if (cub->mode == INTRO || cub->mode == MENU)
		return (0);
	if (button == 1)
		cub->button = 0;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	static int	old_x;
	t_cub3d		*cub;

	(void)y;
	cub = (t_cub3d *)param;
	if (cub->mode == INTRO || cub->mode == MENU)
		return (0);
	if (cub->button == 1)
	{
		rotate_vector(&cub->player.dir, 2 * (x - old_x) / (double)WIDTH);
		rotate_vector(&cub->player.plan, 2 * (x - old_x) / (double)WIDTH);
		set_direction(cub);
	}
	old_x = x;
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_cub3d	*cub;

	(void)x;
	(void)y;
	cub = (t_cub3d *)param;
	if (cub->mode == INTRO || cub->mode == MENU)
		return (0);
	if (button == 1 && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		cub->button = 1;
	else if (button == 4)
		move_player(S, cub);
	else if (button == 5)
		move_player(W, cub);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:56:27 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/10 20:56:46 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	mouse_release(int button, int x, int y, void *param)
{
	t_cub3d	*cub;

	(void)x;
	(void)y;
	cub = (t_cub3d *)param;
	if (cub->mode == INTRO)
		return (0);
	if (button == 1)
		cub->button = 0;
	return (0);	
}

static int	mouse_move(int x, int y, void *param)
{
	static int	old_x;
	t_cub3d		*cub;

	(void)y;
	cub = (t_cub3d *)param;
	if (cub->mode == INTRO)
		return (0);
	if (cub->button == 1)
	{
		rotate_vector(&cub->player.dir, 2 * (old_x - x) / (double)WIDTH);
		rotate_vector(&cub->player.plan, 2 * (old_x - x) / (double)WIDTH);
	}
	old_x = x;
	return (0);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	t_cub3d	*cub;

	(void)x;
	(void)y;
	cub = (t_cub3d *)param;
	if (cub->mode == INTRO)
		return (0);
	if (button == 1)
		cub->button = 1;
	else if (button == 4)
		move_player(S, cub);
	else if (button == 5)
		move_player(W, cub);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:53:19 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/16 11:51:22 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_up(int key, t_cub3d *cub)
{
	if (key == SPACE)
		cub->keys.space = false;
	if (key == RIGHT)
		cub->keys.right = false;
	if (key == LEFT)
		cub->keys.left = false;
	if (key == W)
		cub->keys.w = false;
	if (key == D)
		cub->keys.d = false;
	if (key == S)
		cub->keys.s = false;
	if (key == A)
		cub->keys.a = false;
	return (0);
}

void	update_keys(int key, t_cub3d *cub)
{
	if (key == SPACE)
		cub->keys.space = true;
	if (key == RIGHT)
		cub->keys.right = true;
	if (key == LEFT)
		cub->keys.left = true;
	if (key == W)
		cub->keys.w = true;
	if (key == D)
		cub->keys.d = true;
	if (key == S)
		cub->keys.s = true;
	if (key == A)
		cub->keys.a = true;
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
	update_keys(key, cub);
	return (0);
}

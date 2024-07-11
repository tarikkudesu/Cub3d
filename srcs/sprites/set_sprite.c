/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:45:00 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/10 14:35:09 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	transform_sprite(t_cub3d *cub, double *trans_x, double *trans_y)
{
	double	inv_det;
	double	dx;
	double	dy;

	dx = cub->sprite->x - cub->player.pos.x;
	dy = cub->sprite->y - cub->player.pos.y;
	inv_det = 1.0 / (cub->player.plan.x * cub->player.dir.y \
		- cub->player.dir.x * cub->player.plan.y);
	*trans_x = inv_det * (cub->player.dir.y * dx - cub->player.dir.x * dy);
	*trans_y = inv_det * (cub->player.plan.x * dy - cub->player.plan.y * dx);
}

bool	set_sprite_data(t_cub3d *cub)
{
	int			screen_x;
	double		trans_x;
	double		trans_y;

	if (!is_visible(cub->sprite->x, cub->sprite->y))
		return (false);
	transform_sprite(cub, &trans_x, &trans_y);
	screen_x = (int)((WIDTH / 2) * (1 + trans_x / trans_y));
	cub->sprite->height = abs((int)(HEIGHT / trans_y));
	cub->sprite->width = abs((int)(HEIGHT / trans_y));
	cub->sprite->start_x = -1 * cub->sprite->width / 2 + screen_x;
	cub->sprite->end_x = cub->sprite->width / 2 + screen_x ;
	cub->sprite->start_y = HEIGHT / 2 - cub->sprite->height / 2;
	cub->sprite->end_y = HEIGHT / 2 + cub->sprite->height / 2;
	if (trans_y >= 0)
		return (true);
	return (false);
}

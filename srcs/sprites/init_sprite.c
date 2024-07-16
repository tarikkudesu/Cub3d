/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:09:07 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/16 11:30:11 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	swap_data(double *x, double *y)
{
	double	n;

	n = *x;
	*x = *y;
	*y = n;
}

static void	sort_sprites(t_cub3d *cub)
{
	t_sprite	*list_i;
	t_sprite	*list_j;

	if (!cub->sprites_list || !cub->sprites_list->next)
		return ;
	list_i = cub->sprites_list;
	while (list_i->next)
	{
		list_j = list_i->next;
		while (list_j)
		{
			if (list_j->distance > list_i->distance)
				(swap_data(&list_j->x, &list_i->x), \
				swap_data(&list_j->y, &list_i->y));
			list_j = list_j->next;
		}
		list_i = list_i->next;
	}
}

void	set_distance(t_cub3d *cub)
{
	t_sprite	*sprite;
	double		dx;
	double		dy;

	sprite = cub->sprites_list;
	while (sprite)
	{
		dx = sprite->x - cub->player.pos.x;
		dy = sprite->y - cub->player.pos.y;
		sprite->distance = dx * dx + dy * dy;
		sprite = sprite->next;
	}
	sort_sprites(cub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:48:54 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 13:32:24 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	door_addback(t_door **doors, t_door *door)
{
	t_door *tmp;

	if (!*doors)
	{
		*doors = door;
		return ;
	}
	tmp = *doors;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = door;
}

void new_door(t_cub3d *cub, int x, int y)
{
	t_door *door;

	door = talloc(sizeof(t_door));
	door->x = y;
	door->y	= x;
	door->timer = 0;
	door->isopen = 0;
	door->ismoving = 0;
	door->progress = 0.f;
	door->next = NULL;
	door_addback(&cub->doors, door);
}

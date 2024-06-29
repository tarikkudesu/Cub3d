/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:48:54 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/29 08:03:06 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	door_addback(t_door **doors, t_door *door)
{
	t_door	*tmp;

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

void	new_door(t_cub3d *cub, int x, int y)
{
	t_door	*door;

	door = talloc(sizeof(t_door));
	door->x = x;
	door->y = y;
	door->timer = 0;
	door->isopen = 0;
	door->isopening = false;
	door->isclosing = false;
	door->progress = 0.f;
	door->next = NULL;
	door_addback(&cub->doors, door);
}

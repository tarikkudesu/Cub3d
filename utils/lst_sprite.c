/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:51:06 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 10:33:06 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	sprite_addback(t_sprite **sprites, t_sprite *new)
{
	t_sprite	*tmp;

	if (!*sprites)
	{
		*sprites = new;
		return ;
	}
	tmp = *sprites;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	new_sprite(t_cub3d *cub, int x, int y)
{
	t_sprite	*new;

	new = talloc(&cub->heap, sizeof(t_sprite));
	if (!new)
		return ;
	new->x = y + 0.5;
	new->y = x + 0.5;
	new->visible = false;
	new->distance = 0;
	new->index = 0;
	new->next = NULL;
	sprite_addback(&cub->sprites, new);
}

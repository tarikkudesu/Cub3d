/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:15:50 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/27 09:42:09 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_visible(int x, int y)
{
	t_cub3d	*cub;

	cub = get_cub(NULL);
	if (x >= 0 && x < cub->map_height && y >= 0 && cub->map_width)
		return (cub->map[x][y].visited);
	return (false);
}

bool	is_wall(int x, int y)
{
	t_cub3d	*cub;

	cub = get_cub(NULL);
	if (x >= 0 && x < cub->map_height && y >= 0 && y < cub->map_width)
		return (cub->map[x][y].wall);
	return (false);
}

bool	is_door(int x, int y)
{
	t_cub3d	*cub;

	cub = get_cub(NULL);
	if (x >= 0 && x < cub->map_height && y >= 0 && y < cub->map_width)
		return (cub->map[x][y].door);
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:19:48 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/23 16:41:21 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_door_sprite(t_map **map, int i, int c)
{
	(*map + i)->v = c - 48;
	(*map + i)->door = false;
	if ((*map + i)->v == 2)
		(*map + i)->door = true;
	(*map + i)->wall = false;
	(*map + i)->visited = false;
}

void	set_wall(t_map **map, int i)
{
	(*map + i)->v = 1;
	(*map + i)->door = false;
	(*map + i)->wall = true;
	(*map + i)->visited = false;
}

void	set_space(t_map **map, int i)
{
	(*map + i)->v = 0;
	(*map + i)->door = false;
	(*map + i)->wall = false;
	(*map + i)->visited = false;
}

int	fill_one(t_cub3d *cub, t_map **map, t_line *line, int min)
{
	int	i;

	i = 0;
	while (line->line[i + min] && line->line[i + min] != '\n')
	{
		if (line->line[i + min] == ' ' || line->line[i + min] == '1')
			(set_wall(map, i));
		else if (line->line[i + min] == '2' || line->line[i + min] == '3')
			set_door_sprite(map, i, line->line[i + min]);
		else if (line->line[i + min] == '0')
			set_space(map, i);
		else
			(set_space(map, i), cub->player.pole = line->line[i + min]);
		i++;
	}
	while (i < cub->map_width)
		((*map) + i++)->v = 1;
	return (1);
}

void	get_min_max(t_line *line, int *min, int *max)
{
	*min = line->off;
	*max = line->last;
	while (line)
	{
		if (line->off < *min)
			*min = line->off;
		if (line->last > *max)
			*max = line->last;
		line = line->next;
	}
}

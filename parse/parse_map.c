/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:26:58 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/07/11 17:11:04 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	all_ones(t_line *line)
{
	int	i;

	i = line->off - 1;
	while (line->line[++i] && i <= line->last && line->line[i] != '\n')
	{
		if ((line->line[i] == ' ' && !check_arround(line, i)) \
			|| line->line[i] == '2' || line->line[i] == '3')
			return (0);
	}
	return (i == line->last + 1 || line->line[i] == '\n' || !line->line[i]);
}

int	check_first(t_line *line, int nb_chars)
{
	int	i;

	i = 0;
	while (i < nb_chars)
	{
		if (line->line[i + line->off] == ' ' && !check_arround(line, i))
			return (0);
		i++;
	}
	return (i == nb_chars);
}

int	check_last(t_line *line, int nb_chars)
{
	int	i;
	int	len;

	i = 0;
	len = line->last;
	while (i < nb_chars)
	{
		if (line->line[len - i] == '0')
		{
			if (line->prev && line->prev->last < line->last)
				return (0);
			if (line->next && line->next->last < line->last)
				return (0);
		}
		if (line->line[len - i] == ' ' && !check_arround(line, len - i))
			return (0);
		i++;
	}
	return (i == nb_chars);
}

int	wall_exist(t_line *c_line, t_line *p_line)
{
	if (c_line->off < p_line->off)
		return (check_first(c_line, p_line->off - c_line->off));
	if (c_line->off > p_line->off)
		return (check_first(p_line, c_line->off - p_line->off));
	if (c_line->last > p_line->last)
		return (check_last(c_line, c_line->last - p_line->last));
	if (c_line->last < p_line->last)
		return (check_last(p_line, p_line->last - c_line->last));
	return (1);
}

int	get_map_cord(t_cub3d *cub)
{
	int		i;
	t_line	*line;
	int		min;
	int		max;

	(get_min_max(cub->line, &min, &max), cub->map_width = max - min + 1);
	cub->map = talloc(sizeof(t_map *) * cub->map_height);
	i = 0;
	while (i < cub->map_height)
		(cub->map)[i++] = talloc(sizeof(t_map) * cub->map_width);
	line = cub->line;
	i = 0;
	while (line)
	{
		if (!fill_one(cub, cub->map + i++, line, min))
			return (0);
		line = line->next;
	}
	return (1);
}

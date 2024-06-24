/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:26:58 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/23 16:40:52 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	all_ones(char *line)
{
	line = ft_strtrim(line, " ");
	while (*line && *line == '1')
		line++;
	return (*line == '\n' || !*line);
}

int	check_first(t_line *line, int nb_chars)
{
	int	i;

	i = 0;
	while (i < nb_chars && line->line[i + line->off] == '1')
		i++;
	return (i == nb_chars);
}

int	check_last(t_line *line, int nb_chars)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line->line);
	while (i < nb_chars && line->line[len - 2 - i] == '1')
		i++;
	return (i == nb_chars);
}

int	wall_exist(int front, int less, t_line *c_line, t_line *p_line)
{
	if (front)
	{
		if (less)
			return (check_first(c_line, p_line->off - c_line->off));
		return (check_first(p_line, c_line->off - p_line->off));
	}
	else
	{
		if (less)
			return (check_last(p_line, p_line->last - c_line->last));
		return (check_last(c_line, c_line->last - p_line->last));
	}
}

int	get_map_cord(t_cub3d *cub)
{
	int		i;
	t_line	*line;
	int		min;
	int		max;

	(get_min_max(cub->line, &min, &max), cub->map_width = max - min + 1);
	cub->map = talloc(&cub->heap, sizeof(t_map *) * cub->map_height);
	i = 0;
	while (i < cub->map_height)
		(cub->map)[i++] = talloc(&cub->heap, sizeof(t_map) * cub->map_width);
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

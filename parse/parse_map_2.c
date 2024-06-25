/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:33:06 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/25 18:39:59 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_pos(char *line, int index)
{
	return (line[index] == ' ' || line[index] == '1');
}

int	check_arround(t_line *line, int i)
{
	if (!valid_pos(line->line, i - 1) || !valid_pos(line->line, i + 1))
		return (0);
	if (line->prev && i < line->prev->last - line->prev->off && \
		!valid_pos(line->prev->line, i))
		return (0);
	if (line->next && i < line->next->last - line->next->off && \
		!valid_pos(line->next->line, i))
		return (0);
	return (1);
}

int	parse_map(t_cub3d *cub)
{
	int		i;
	t_line	*curr;

	curr = cub->line;
	if (!all_ones(curr))
		return (0);
	while (curr->next)
	{
		if (curr->prev && (!wall_exist(curr, curr->prev)))
			return (0);
		if (curr->line[curr->off] != '1' || curr->line[curr->last] != '1')
			return (0);
		i = 0;
		while (curr->line[++i] != '\n')
			if (curr->line[i] == ' ' && !check_arround(curr, i))
				return (0);
		curr = curr->next;
	}
	return (all_ones(curr));
}

int	parse_line(t_cub3d *cub, char *line, int *off, int *last)
{
	int			i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	*off = i;
	while (line[i])
	{
		while (line[i] && valid_char(cub, line[i]))
			i++;
		if (line[i] && line [i] != ' ' && line [i] != '\n')
			return (0);
		*last = i - 1;
		while (line[i] && (line[i] == ' ' || line[i] == '\n'))
			i++;
	}
	return (1);
}

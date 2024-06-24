/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:29:12 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/23 15:32:19 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_map(t_cub3d *cub)
{
	t_line	*c_line;
	t_line	*p_line;

	p_line = cub->line;
	if (!all_ones(p_line->line))
		return (0);
	while (p_line->next)
	{
		c_line = p_line->next;
		if (c_line->off < p_line->off && !wall_exist(1, 1, c_line, p_line))
			return (0);
		if (c_line->off > p_line->off && !wall_exist(1, 0, c_line, p_line))
			return (0);
		c_line = p_line->next;
		if (c_line->last < p_line->last && !wall_exist(0, 1, c_line, p_line))
			return (0);
		if (c_line->last > p_line->last && !wall_exist(0, 0, c_line, p_line))
			return (0);
		if (c_line->line[c_line->off] != '1' \
		|| c_line->line[c_line->last] != '1')
			return (0);
		p_line = c_line;
		c_line = c_line->next;
	}
	return (all_ones(p_line->line));
}

int	parse_line(char *line, int *off, int *last)
{
	static int	bol;
	int			i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	*off = i;
	while (line[i])
	{
		while (line[i] && line[i] != '\n' && valid_char(line[i]) \
		&& line[i] != ' ')
		{
			if (line[i] == 'N' || line[i] == 'E' || line[i] == 'W' \
			|| line[i] == 'S')
				bol++;
			i++;
		}
		if (bol > 1 || (line[i] && line[i] != ' ' && !valid_char(line[i])))
			return (0);
		*last = i - 1;
		while (line[i] && (line[i] == ' ' || line[i] == '\n'))
			i++;
	}
	return (1);
}

int	valid_map(t_cub3d *cub, int fd)
{
	char	*line;
	t_line	*node;
	int		first;
	int		last;

	line = get_next_line(fd);
	while (line && empty(line))
		(free(line), line = get_next_line(fd));
	while (line)
	{
		if (!parse_line(line, &first, &last))
			return (0);
		node = new_line(cub, line, first, last);
		if (!node)
			return (0);
		line_add_back(&cub->line, node);
		cub->map_height++;
		line = get_next_line(fd);
	}
	if (cub->map_height < 3)
		return (0);
	return (parse_map(cub) && get_map_cord(cub));
}

int	headers_parse(t_cub3d *cub, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < 6)
	{
		if (!empty(line)) // the line maybe empty
		{
			if (!valid_component(cub, line))
				return (0);
			i++;
		}
		free(line);
		if (i < 6) //in order to not lose the offset of the first line of map
			line = get_next_line(fd);
	}
	return (line != NULL);
}

int	file_parse(t_cub3d *cub, char *file)
{
	int	fd;

	if (ft_strcmp(ft_strrchr(file, '.'), ".cub"))
		return (putendl_fd("Error\nnot valid Extention", 2), 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (putendl_fd("error\nfail to open file", 2), 0);
	if (!headers_parse(cub, fd))
		return (putendl_fd("Error\nnot valid Headers", 2), 0);
	if (!valid_map(cub, fd))
		return (putendl_fd("Error\nnot a valid map", 2), 0);
	return (close(fd), 1);
}
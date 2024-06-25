/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:29:12 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/25 16:41:22 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_map(t_cub3d *cub, int fd)
{
	char	*line;
	t_line	*node;
	int		first;
	int		last;

	line = get_next_line(fd);
	while (line && empty(line))
		line = get_next_line(fd);
	while (line)
	{
		if (empty(line))
			return (0);
		if (!parse_line(cub, line, &first, &last))
			return (0);
		node = new_line(line, first, last);
		line_add_back(&cub->line, node);
		cub->map_height++;
		line = get_next_line(fd);
	}
	if (cub->map_height < 3 || cub->map_height > 100)
		return (0);
	return (cub->player_nbr == 1 && parse_map(cub) && get_map_cord(cub));
}

int	headers_parse(t_cub3d *cub, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < 6)
	{
		if (!empty(line))
		{
			if (!valid_component(cub, line))
				return (0);
			i++;
		}
		if (i < 6)
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

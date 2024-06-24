/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:24:39 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/24 19:49:39 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	parse_color(t_color *color, char *line)
{
	char	**splited;

	if (!is_num(line[ft_strlen(line) - 1]))
		return (0);
	splited = ft_split(line, ',');
	if (count(splited) != 3 && (!all_num(ft_strtrim(splited[0], " ")) \
	|| !all_num(ft_strtrim(splited[1], " ")) \
	|| !all_num(ft_strtrim(splited[2], " "))))
		return (0);
	color->red = ft_atoi(splited[0]);
	color->green = ft_atoi(splited[1]);
	color->blue = ft_atoi(splited[2]);
	return (1);
}

int	parse_texture(t_cub3d *cub, char *line, int i)
{
	char	**splited;

	splited = ft_split(line, ' ');
	if (count(splited) != 2)
		return (0);
	cub->tex[i].file = ft_strdup(splited[1]);
	return (1);
}

int	valid_component(t_cub3d *cub, char *line)
{
	char	*trim;

	trim = ft_strtrim(line, " \n");
	if (!ft_strncmp(trim, "NO ", 3))
		return (parse_texture(cub, trim, 0), 1);
	if (!ft_strncmp(trim, "EA ", 3))
		return (parse_texture(cub, trim, 1), 1);
	if (!ft_strncmp(trim, "SO ", 3))
		return (parse_texture(cub, trim, 2), 1);
	if (!ft_strncmp(trim, "WE ", 3))
		return (parse_texture(cub, trim, 3), 1);
	if (!ft_strncmp(trim, "F ", 2))
		return (parse_color(&cub->floor_color, ft_strchr(trim, ' ')));
	if (!ft_strncmp(trim, "C ", 2))
		return (parse_color(&cub->ceiling_color, ft_strchr(trim, ' ')));
	return (0);
}

int	empty(char *str)
{
	while (*str && (*str == ' ' || *str == '\n'))
		str++;
	return (!*str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:02:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/11 22:33:30 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	initialize_data(t_cub3d *cub)
{
	if (Z) {atexit(leaks);}
	cub->gun = 0;
	cub->button = 0;
	cub->doors_n = 1;
	cub->heap = NULL;
	cub->doors = NULL;
	cub->mode = INTRO;
	cub->wall_width = 20;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->player.pos.x = 7.2;
	cub->player.pos.y = 4.2;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.plan.x = 0;
	cub->player.pole = EASTH;
	cub->player.plan.y = 0.66;
	cub->map_width = mapHeight;
	cub->map_height = mapWidth;
	cub->floor_color = hex_to_rgb(0x000000);
	cub->ceiling_color = hex_to_rgb(0x000000);
	cub->tex[0].file = ft_strdup("xpm/south.xpm");
	cub->tex[1].file = ft_strdup("xpm/north.xpm");
	cub->tex[2].file = ft_strdup("xpm/west.xpm");
	cub->tex[3].file = ft_strdup("xpm/east.xpm");
}

int	main()
{
	t_cub3d	cub;

	initialize_data(&cub);
	init_doors(&cub);
	if (init_window(&cub))
		return (0);
}

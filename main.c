/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:02:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/10 19:15:14 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	initialize_data(t_cub3d *cub)
{
	if (Z) {atexit(leaks);}
	cub->mode = 1;
	cub->button = 0;
	cub->heap = NULL;
	cub->wall_width = 20;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->player.pos.x = 1.2;
	cub->player.pos.y = 1.2;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.plan.x = 0;
	cub->player.pole = EASTH;
	cub->player.plan.y = 0.66;
	cub->map_width = mapWidth;
	cub->map_height = mapHeight;
	cub->ceiling_color = hex_to_rgb(0x000000);
	cub->floor_color = hex_to_rgb(0x000000);
	cub->tex[0].file = ft_strdup("assets/south.xpm");
	cub->tex[1].file = ft_strdup("assets/north.xpm");
	cub->tex[2].file = ft_strdup("assets/west.xpm");
	cub->tex[3].file = ft_strdup("assets/east.xpm");
}

int	main()
{
	t_cub3d	cub;

	initialize_data(&cub);
	if (init_window(&cub))
		return (0);
}

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
	cub->player.pos.x = 1.2;
	cub->player.pos.y = 1.2;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.plan.x = 0;
	cub->player.pole = EASTH;
	cub->player.plan.y = 0.66;
	cub->map_width = mapHeight;
	cub->map_height = mapWidth;
	cub->floor_color = hex_to_rgb(0x000000);
	cub->ceiling_color = hex_to_rgb(0x000000);
	cub->tex[0].file = ft_strdup("orange/south.xpm");
	cub->tex[1].file = ft_strdup("orange/north.xpm");
	cub->tex[2].file = ft_strdup("orange/west.xpm");
	cub->tex[3].file = ft_strdup("orange/east.xpm");
}

int	main()
{
	t_cub3d	cub;

	initialize_data(&cub);
	cub.doors = talloc(&cub.heap, sizeof(t_door) * cub.doors_n); _MAL_CALL_INFO();
	if (!cub.doors)
		return (1);
	cub.doors->progress = 0;
	cub.doors->ismoving = 0;
	cub.doors->isopen = 0;
	cub.doors->x = 21;
	cub.doors->y = 1;
	if (init_window(&cub))
		return (0);
}

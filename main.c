/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:02:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/06 19:20:29 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	initialize_data(t_cub3d *cub)
{
	if (Z) {atexit(leaks);}
	cub->panel = 1;
	cub->heap = NULL;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->player.pos.x = 12;
	cub->player.pos.y = 12;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.plan.x = 0;
	cub->player.plan.y = 0.66;
	cub->wall_width = 64;
	cub->map_width = mapWidth;
	cub->map_height = mapHeight;
}

int	main()
{
	t_cub3d	cub;

	initialize_data(&cub);
	if (init_window(&cub))
		return (0);
}

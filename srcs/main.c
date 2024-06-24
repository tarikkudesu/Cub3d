/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:29:48 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 11:19:21 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	cub;

	if (ac != 2)
		return (putendl_fd("Error\nbad number of arguments", 2), 1);
	initialize_data(&cub);
	if (!file_parse(&cub, av[1]))
		return (2);
	// printf("width : %d height : %d\n", cub.map_width, cub.map_height);
	// printf("pole %c\n", cub.player.pole);
	// printf("floor : (%d %d %d), ceiling : (%d %d %d)\n", cub.floor_color.red, cub.floor_color.green, cub.floor_color.blue, cub.ceiling_color.red, cub.ceiling_color.green, cub.ceiling_color.blue);
	// printf("%s\n", cub.tex[0].file);
	// printf("%s\n", cub.tex[1].file);
	// printf("%s\n", cub.tex[2].file);
	// printf("%s\n", cub.tex[3].file);
	// for (int i = 0; i < cub.map_height; i++) {
	// 	for (int j = 0; j < cub.map_width; j++)
	// 		printf("(%d %d %d) ", cub.map[i][j].v, cub.map[i][j].wall, cub.map[i][j].door);
	// 	printf("\n");
	// }
	set_data(&cub);
	// t_door *doors = cub.doors;
	// while (doors)
	// {
	// 	printf("%d %d %d %d %f\n", doors->x, doors->y, doors->isopen, doors->ismoving, doors->progress);
	// 	doors = doors->next;
	// }
	t_sprite *sprites = cub.sprites;
	while (sprites)
	{
		printf("%f %f\n", sprites->x, sprites->y);
		sprites = sprites->next;
	}
	if (init_window(&cub))
		return (0);
}

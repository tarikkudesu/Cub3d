/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:36:29 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/11 22:41:51 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// extern int worldMap[mapWidth][mapHeight];

static void	put_block(int x, int y, t_cub3d *cub, int flag)
{
	int	w;
	int	h;

	w = x - 1;
	if (flag)
		set_color(true, WHITE);
	else
		set_color(true, MAGENTA);
	while (++w < x + cub->wall_width)
	{
		h = y - 1;
		while (++h < y + cub->wall_width)
			minimap_pixel_put(w, h, &cub->img);
	}
}

static void	put_background(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 40;
	// set_color(true, 0x142F3B);
	set_color(true, BACKGROUND);
	while (i < 240)
	{
		j = 40;
		while (j < 240)
			minimap_pixel_put(i, j++, &cub->img);
		i++;
	}
}

static void	put_minimap(t_cub3d *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->map_height)
	{
		j = -1;
		while (++j < cub->map_width)
		{
			if (is_wall(cub, i, j))
				put_block((i - cub->player.pos.x) * 20 + 140, \
					(j - cub->player.pos.y) * 20 + 140, cub, 1);
		}
	}
}

static void	put_dir_rays(t_cub3d *cub)
{
	t_vect	start;
	t_vect	end;
	t_vect	dir;
	int		i;

	i = -1;
	start.x = 140;
	start.y = 140;
	set_color(true, 0x74f9ff);
	dir.x = cub->player.dir.x;
	dir.y = cub->player.dir.y;
	rotate_vector(&dir, - PI_1 * 30);
	while (++i < 60)
	{
		rotate_vector(&dir, PI_1);
		end.x = start.x + 100 * dir.x;
		end.y = start.y + 100 * dir.y;
		draw_line(&start, &end, &cub->img);
	}
}

static	void	put_player(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 137;
	while (++i < 142)
	{
		j = 137;
		while (++j < 142)
			minimap_pixel_put(i, j, &cub->img);
	}
}

void	minimap(t_cub3d *cub)
{
	put_background(cub);
	put_minimap(cub);
	put_dir_rays(cub);
	put_player(cub);
}
/* ------------------------------------------------------------------------- */
// static void	put_block(int x, int y, t_cub3d *cub, int flag)
// {
// 	int	w;
// 	int	h;

// 	w = x - 1;
// 	if (flag)
// 		set_color(true, WHITE);
// 	else
// 		set_color(true, MAGENTA);
// 	while (++w < x + cub->wall_width)
// 	{
// 		h = y - 1;
// 		while (++h < y + cub->wall_width)
// 			my_mlx_pixel_put(w, h, &cub->minimap);
// 	}
// }

// static void	put_background(t_cub3d *cub)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	// set_color(true, 0x142F3B);
// 	set_color(true, BACKGROUND);
// 	while (i < WIDTH)
// 	{
// 		j = 0;
// 		while (j < HEIGHT)
// 			my_mlx_pixel_put(i, j++, &cub->minimap);
// 		i++;
// 	}
// }

// static void	put_minimap(t_cub3d *cub)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < cub->map_height)
// 	{
// 		j = -1;
// 		while (++j < cub->map_width)
// 		{
// 			if (worldMap[i][j] == 1)
// 				put_block((i - cub->player.pos.x) * 20 + 500, 
// 					(j - cub->player.pos.y) * 20 + 500, cub, 1);
// 			// else if (worldMap[i][j] == 2)
// 			// 	put_block((i - cub->player.pos.x) * 20 + 140,
// 			// 		(j - cub->player.pos.y) * 20 + 140, cub, 0);
// 		}
// 	}
// }

// static void	put_dir_rays(t_cub3d *cub)
// {
// 	t_vect	start;
// 	t_vect	end;
// 	t_vect	dir;
// 	int		i;

// 	i = -1;
// 	start.x = 500;
// 	start.y = 500;
// 	set_color(true, 0x74f9ff);
// 	dir.x = cub->player.dir.x;
// 	dir.y = cub->player.dir.y;
// 	rotate_vector(&dir, - PI_1 * 30);
// 	while (++i < 60)
// 	{
// 		rotate_vector(&dir, PI_1);
// 		end.x = start.x + 100 * dir.x;
// 		end.y = start.y + 100 * dir.y;
// 		draw_line(&start, &end, &cub->minimap);
// 	}
// }

// static	void	put_player(t_cub3d *cub)
// {
// 	int	i;
// 	int	j;

// 	i = 497;
// 	while (++i < 502)
// 	{
// 		j = 497;
// 		while (++j < 502)
// 			my_mlx_pixel_put(i, j, &cub->minimap);
// 	}
// }

// void	minimap(t_cub3d *cub)
// {
// 	put_background(cub);
// 	put_minimap(cub);
// 	put_dir_rays(cub);
// 	put_player(cub);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:49:03 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/27 09:17:57 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_mlx(t_cub3d *cub)
{
	cub->mlx.__mlx = mlx_init();
	if (!cub->mlx.__mlx)
		terror(ERR_MLX_INIT);
	cub->mlx.__win = mlx_new_window(cub->mlx.__mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->mlx.__win)
		terror(ERR_MLX_WIN);
	cub->img.__img = mlx_new_image(cub->mlx.__mlx, WIDTH, HEIGHT);
	if (!cub->img.__img)
		terror(ERR_MLX_IMG);
	cub->img.__addr = (int *)mlx_get_data_addr(cub->img.__img, \
	&cub->img.pixel_bits, &cub->img.line_bytes, &cub->img.endian);
	if (!cub->img.__addr)
		terror(ERR_MLX_ADDRESS);
	init_textures(cub);
}

void	init_window(t_cub3d *cub)
{
	init_mlx(cub);
	mlx_loop_hook(cub->mlx.__mlx, update_frame, cub);
	mlx_hook(cub->mlx.__win, 2, 0, handle_key, cub);
	mlx_hook(cub->mlx.__win, 6, 0, mouse_move, cub);
	mlx_hook(cub->mlx.__win, 4, 0, mouse_press, cub);
	mlx_hook(cub->mlx.__win, 5, 0, mouse_release, cub);
	mlx_hook(cub->mlx.__win, 17, 0, exit_program, cub);
	mlx_loop(cub->mlx.__mlx);
}

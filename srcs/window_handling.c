/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:54:12 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/04 11:32:55 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int	init_mlx(t_cub3d *cub)
{
	int	a[2];

	cub->mlx.__mlx = mlx_init();
	if (!cub->mlx.__mlx)
		return (putendl_fd(ERR_MLX_INIT, 2), 1);
	cub->mlx.__win = mlx_new_window(cub->mlx.__mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->mlx.__win)
		return (putendl_fd(ERR_MLX_WIN, 2), 1);
	cub->mlx.__intro = mlx_xpm_file_to_image(cub->mlx.__mlx, "assets/intro_white.xpm", a, a + 1);
	if (!cub->mlx.__intro)
		return (putendl_fd(ERR_MLX_XPM, 2), 1);
	cub->img.__img = mlx_new_image(cub->mlx.__mlx, WIDTH, HEIGHT);
	if (!cub->img.__img)
		(putendl_fd(ERR_MLX_IMG, 2), exit(EXIT_FAILURE));
	cub->img.__addr = mlx_get_data_addr(cub->img.__img, &cub->img.pixel_bits, \
	&cub->img.line_bytes, &cub->img.endian);
	if (!cub->img.__addr)
		(putendl_fd(ERR_MLX_ADDRESS, 2), exit(EXIT_FAILURE));
	return (0);	
}

int	init_window(t_cub3d *cub)
{
	if (init_mlx(cub))
		return (1);
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			my_mlx_pixel_put(i, j, &cub->img);
		}
	}
	mlx_loop_hook(cub->mlx.__mlx, update_frame, cub);
	mlx_hook(cub->mlx.__win, 2, 0, handle_key, cub);
	mlx_hook(cub->mlx.__win, 17, 0, exit_program, cub);
	mlx_loop(cub->mlx.__mlx);
	return (0);
}
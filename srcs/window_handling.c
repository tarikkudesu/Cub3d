/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:54:12 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/11 22:20:10 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_sprites(t_cub3d *cub)
{
	cub->sprite_img.__img = mlx_xpm_file_to_image(cub->mlx.__mlx, \
		"xpm/gris/sprite.xpm", &cub->sprite_img.width, &cub->sprite_img.height);
	if (!cub->sprite_img.__img)
		(putendl_fd(ERR_MLX_IMG, 2), exit(EXIT_FAILURE));
	cub->sprite_img.__addr = \
		(int *)mlx_get_data_addr(cub->sprite_img.__img, \
		&cub->sprite_img.pixel_bits, &cub->sprite_img.line_bytes, \
		&cub->sprite_img.endian);
	if (!cub->sprite_img.__addr)
		(putendl_fd(ERR_MLX_ADDRESS, 2), exit(EXIT_FAILURE));
	return (0);
}

static int	init_xpm(t_cub3d *cub)
{
	int	a[2];

	cub->mlx.__intro = mlx_xpm_file_to_image(cub->mlx.__mlx, \
		"xpm/gris/intro.xpm", a, a + 1);
	if (!cub->mlx.__intro)
		return (putendl_fd(ERR_MLX_XPM, 2), 1);
	// cub->mlx.__gun = mlx_xpm_file_to_image(cub->mlx.__mlx, 
	// 	"assets/gun.xpm", a, a + 1);
	// if (!cub->mlx.__gun)
	// 	return (putendl_fd(ERR_MLX_XPM, 2), 1);
	// cub->mlx.__gun_shot = mlx_xpm_file_to_image(cub->mlx.__mlx, 
	// 	"assets/gun_shot.xpm", a, a + 1);
	// if (!cub->mlx.__gun_shot)
	// 	return (putendl_fd(ERR_MLX_XPM, 2), 1);
	cub->mlx.__menu = mlx_xpm_file_to_image(cub->mlx.__mlx, \
		"xpm/gris/controls.xpm", a, a + 1);
	if (!cub->mlx.__menu)
		return (putendl_fd(ERR_MLX_XPM, 2), 1);
	return (init_sprites(cub));
}

static int	init_textures(t_cub3d *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		cub->tex[i].img.__img = mlx_xpm_file_to_image(cub->mlx.__mlx, \
			cub->tex[i].file, &cub->tex[i].img.width, &cub->tex[i].img.height);
		if (!cub->tex[i].img.__img)
			(putendl_fd(ERR_MLX_XPM, 2), exit(EXIT_FAILURE));
		cub->tex[i].img.__addr = \
			(int *)mlx_get_data_addr(cub->tex[i].img.__img, \
			&cub->tex[i].img.pixel_bits, &cub->tex[i].img.line_bytes, \
			&cub->tex[i].img.endian);
		if (!cub->tex[i].img.__addr)
			(putendl_fd(ERR_MLX_ADDRESS, 2), exit(EXIT_FAILURE));
	}
	cub->tex[i].img.__img = mlx_xpm_file_to_image(cub->mlx.__mlx, \
		"xpm/gris/door.xpm", &cub->tex[i].img.width, &cub->tex[i].img.height);
	if (!cub->tex[i].img.__img)
		(putendl_fd(ERR_MLX_IMG, 2), exit(EXIT_FAILURE));
	cub->tex[i].img.__addr = \
		(int *)mlx_get_data_addr(cub->tex[i].img.__img, \
		&cub->tex[i].img.pixel_bits, &cub->tex[i].img.line_bytes, \
		&cub->tex[i].img.endian);
	if (!cub->tex[i].img.__addr)
		(putendl_fd(ERR_MLX_ADDRESS, 2), exit(EXIT_FAILURE));
	return (init_xpm(cub));
}

static int	init_mlx(t_cub3d *cub)
{
	cub->mlx.__mlx = mlx_init();
	if (!cub->mlx.__mlx)
		return (putendl_fd(ERR_MLX_INIT, 2), 1);
	cub->mlx.__win = mlx_new_window(cub->mlx.__mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->mlx.__win)
		return (putendl_fd(ERR_MLX_WIN, 2), 1);
	cub->img.__img = mlx_new_image(cub->mlx.__mlx, WIDTH, HEIGHT);
	if (!cub->img.__img)
		(putendl_fd(ERR_MLX_IMG, 2), exit(EXIT_FAILURE));
	cub->img.__addr = (int *)mlx_get_data_addr(cub->img.__img, \
	&cub->img.pixel_bits, &cub->img.line_bytes, &cub->img.endian);
	if (!cub->img.__addr)
		(putendl_fd(ERR_MLX_ADDRESS, 2), exit(EXIT_FAILURE));
	return (init_textures(cub));
}

int	init_window(t_cub3d *cub)
{
	if (init_mlx(cub))
		return (1);
	// mlx_hook(cub->mlx.__win, 2, 0, handle_key, cub);
	mlx_loop_hook(cub->mlx.__mlx, update_frame, cub);
	mlx_hook(cub->mlx.__win, 2, 1L<<0, handle_key, cub); // Linux
	mlx_hook(cub->mlx.__win, 6, 0, mouse_move, cub);
	mlx_hook(cub->mlx.__win, 4, 0, mouse_press, cub);
	mlx_hook(cub->mlx.__win, 5, 0, mouse_release, cub);
	mlx_hook(cub->mlx.__win, 17, 0, exit_program, cub);
	mlx_loop(cub->mlx.__mlx);
	return (0);
}

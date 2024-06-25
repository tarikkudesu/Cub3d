/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:04:00 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 17:26:31 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*get_name(int c, bool f)
{
	int		i;
	int		j;
	char	*name;
	char	*prename;
	char	*postname;

	i = -1;
	name = talloc(sizeof(char) * 21);
	if (!name)
		return (NULL);
	prename = ft_strdup("assets/sprite/");
	postname = ft_strdup(".xpm");
	while (*(prename + ++i))
		*(name + i) = *(prename + i);
	*(name + i++) = c;
	if (f)
		*(name + i++) = c;
	j = 0;
	while (*(postname + j))
		*(name + i++) = *(postname + j++);
	*(name + i) = '\0';
	return (name);
}

static void	init_sprites(t_cub3d *cub)
{
	int	i;

	i = -1;
	while (++i < 40)
	{
		if (i < 20)
			cub->frames[i] = get_name(i + 'a', false);
		else
			cub->frames[i] = get_name(i + 'a' - 20, true);
		cub->sprite_img[i].__img = create_image(cub->frames[i], \
			&cub->sprite_img[i].width, &cub->sprite_img[i].height);
		cub->sprite_img[i].__addr = \
			(int *)mlx_get_data_addr(cub->sprite_img[i].__img, \
			&cub->sprite_img[i].pixel_bits, &cub->sprite_img[i].line_bytes, \
			&cub->sprite_img[i].endian);
		if (!cub->sprite_img[i].__addr)
			terror(ERR_MLX_ADDRESS);
	}
}

static void	init_xpm(t_cub3d *cub)
{
	int	a[2];

	cub->mlx.__intro = create_image("assets/ui/intro.xpm", \
		a, a + 1);
	cub->mlx.__menu = create_image("assets/ui/controls.xpm", \
		a, a + 1);
	cub->tex[4].img.__img = create_image("assets/nova/door.xpm", \
		&cub->tex[4].img.width, &cub->tex[4].img.height);
	cub->tex[4].img.__addr = \
		(int *)mlx_get_data_addr(cub->tex[4].img.__img, \
		&cub->tex[4].img.pixel_bits, &cub->tex[4].img.line_bytes, \
		&cub->tex[4].img.endian);
	if (!cub->tex[4].img.__addr)
		terror(ERR_MLX_ADDRESS);
	init_sprites(cub);
}

void	init_textures(t_cub3d *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		cub->tex[i].img.__img = create_image(cub->tex[i].file, \
			&cub->tex[i].img.width, &cub->tex[i].img.height);
		cub->tex[i].img.__addr = \
			(int *)mlx_get_data_addr(cub->tex[i].img.__img, \
			&cub->tex[i].img.pixel_bits, &cub->tex[i].img.line_bytes, \
			&cub->tex[i].img.endian);
		if (!cub->tex[i].img.__addr)
			terror(ERR_MLX_ADDRESS);
	}
	init_xpm(cub);
}

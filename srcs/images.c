/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:04:00 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 20:22:38 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*create_xpm_image(t_cub3d *cub)
{
	
}

void	*create_image(char *filename, int width, int *height)
{
	t_imgcontainer	*node;
	void			*__img;
	t_cub3d			*cub;

	cub = get_cub(NULL);
	__img = mlx_xpm_file_to_image(cub->mlx.__mlx, filename, width, height);
	if (!__img)
		exit_program(cub);
	node = image_new(__img);
	if (!node)
	{
		mlx_destroy_image(cub->mlx.__mlx, __img);
		exit_program(cub);
	}
	image_addback(&cub->imgcontainer, __img);
	return (__img);
}

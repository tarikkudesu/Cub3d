/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:59:34 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 10:22:57 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	terror(char *__err__message)
{
	t_cub3d	*cub;

	putendl_fd(__err__message, 2);
	cub = get_cub(NULL);
	destroy_images(cub->imgcontainer);
	if (cub->img.__img)
		mlx_destroy_image(cub->mlx.__mlx, cub->img.__img);
	if (cub->mlx.__win)
		mlx_destroy_window(cub->mlx.__mlx, cub->mlx.__win);
	clearheap(&cub->heap);
	exit(EXIT_FAILURE);
}

int	exit_program(t_cub3d *cub)
{
	destroy_images(cub->imgcontainer);
	mlx_destroy_image(cub->mlx.__mlx, cub->img.__img);
	mlx_destroy_window(cub->mlx.__mlx, cub->mlx.__win);
	clearheap(&cub->heap);
	exit(0);
}

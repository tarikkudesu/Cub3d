/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:02:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/05/15 12:57:48 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	initialize_data(t_cub3d *cub3d)
{
	if (D) {atexit(leaks);}
	cub3d->heap = NULL;
}

int	main()
{
	t_cub3d	cub3d;

	initialize_data(&cub3d);
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 500, 500, "cub3d");
	mlx_loop(mlx);
}
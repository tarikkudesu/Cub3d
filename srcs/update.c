/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:18:34 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/03 18:01:46 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	update_frame(void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	if (cub->panel == INTRO)
		mlx_put_image_to_window(cub->mlx.__mlx, \
			cub->mlx.__win, cub->mlx.__intro, 0, 0);
	else if (cub->panel == GAME)
		put_frame_to_image(cub);
	return (0);
}

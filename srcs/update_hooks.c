/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:19:21 by tamehri           #+#    #+#             */
/*   Updated: 2024/07/11 20:24:39 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	update_hooks(t_cub3d *cub)
{
	if (cub->keys.w || cub->keys.s || cub->keys.d || cub->keys.a)
		move_player(cub);
	else if (cub->keys.right || cub->keys.left)
		rotate_player(cub);
	else if (cub->keys.space )
		open_doors(cub);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:00:40 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 17:32:04 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_cub3d	*get_cub(t_cub3d *cub)
{
	static t_cub3d	*cub_s;

	if (cub)
		cub_s = cub;
	return (cub_s);
}

void	*talloc(size_t __size)
{
	void	*__ptr;
	t_heap	*__node;
	t_cub3d	*__cub;

	__cub = get_cub(NULL);
	__ptr = malloc(__size);
	if (__ptr == NULL)
		terror(ERR_MAL);
	__node = heap_new(__ptr);
	if (!__node)
		(free(__ptr), terror(ERR_MAL));
	heap_addback(&__cub->heap, __node);
	return (__ptr);
}

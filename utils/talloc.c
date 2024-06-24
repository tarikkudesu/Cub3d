/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:00:40 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 20:12:10 by tamehri          ###   ########.fr       */
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

void	leaks(void)
{
	system("leaks cub3D");
}

void	*talloc(size_t __size)
{
	void	*__ptr;
	t_heap	*__node;
	t_cub3d	*__cub;

	__cub = get_cub(NULL);
	__ptr = malloc(__size);
	if (__ptr == NULL)
		return (NULL);
	__node = heap_new(__ptr);
	if (!__node)
		return (free(__ptr), NULL);
	heap_add_back(&__cub->heap, __node);
	// if (Z)
		// printf("pointer \033[32m%p\033[0m was allocated, size : \
		// 	\033[32m%ld\033[0m\n", __ptr, __size);
	return (__ptr);
}
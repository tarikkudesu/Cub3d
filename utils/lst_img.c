/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:09:00 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 10:30:59 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	destroy_images(t_imgcontainer *node)
{
	t_cub3d			*cub;

	if (!node)
		return ;
	cub = get_cub(NULL);
	while (node)
	{
		mlx_destroy_image(cub->mlx.__mlx, node->image);
		node = node->next;
	}
}

static void	image_addback(t_imgcontainer **lst, t_imgcontainer *new)
{
	t_imgcontainer	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

static t_imgcontainer	*image_new(void *content)
{
	t_imgcontainer	*head;

	head = talloc(sizeof(t_imgcontainer));
	head->image = content;
	head->next = NULL;
	return (head);
}

void	*create_image(char *filename, int *width, int *height)
{
	void			*__img;
	t_imgcontainer	*node;
	t_cub3d			*cub;

	cub = get_cub(NULL);
	__img = mlx_xpm_file_to_image(cub->mlx.__mlx, filename, width, height);
	if (!__img)
		terror(ERR_MLX_XPM);
	node = image_new(__img);
	image_addback(&cub->imgcontainer, node);
	return (__img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:09:00 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 20:20:21 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	image_addback(t_imgcontainer **lst, t_imgcontainer *new)
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

t_imgcontainer	*image_new(void *content)
{
	t_imgcontainer	*head;

	head = (t_heap *)malloc(sizeof(t_imgcontainer));
	if (!head)
		return (NULL);
	head->image = content;
	head->next = NULL;
	return (head);
}

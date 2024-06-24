/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:04 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/24 20:12:03 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clearheap(t_heap **node)
{
	t_heap	*tmp;

	if (!node || !*node)
		return ;
	tmp = *node;
	while (node && *node)
	{
		free(tmp->ptr);
		tmp->ptr = NULL;
		tmp = tmp->next;
		free(*node);
		*node = tmp;
	}
}

void	heap_addback(t_heap **lst, t_heap *new)
{
	t_heap	*temp;

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

t_heap	*heap_new(void *content)
{
	t_heap	*head;

	head = (t_heap *)malloc(sizeof(t_heap));
	if (!head)
		return (NULL);
	head->ptr = content;
	head->next = NULL;
	return (head);
}

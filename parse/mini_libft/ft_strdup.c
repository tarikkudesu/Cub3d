/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:56:31 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/24 19:41:12 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)talloc((ft_strlen((char *)s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (*(s1 + i))
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}

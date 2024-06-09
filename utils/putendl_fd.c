/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:55:29 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/09 21:04:58 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = ft_strlen(s1);
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(res + i) = *(s1 + i);
		i++;
	}
	*(res + i) = '\0';
	return (res);
}
